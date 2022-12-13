#pragma once
#include <vector>
#include <iostream>
#ifndef VECTOR_PAIR
#define LD long double
#define VECTOR_PAIR std::vector<std::pair<LD, LD>>
#define PAIR_VEC std::pair<std::vector<LD>, std::vector<LD>>
#endif


class RK4
{
public:
  explicit RK4(const LD& _x0 = NULL, const LD& _u0 = 1.0,
               const LD& _du0 = 1.0) : x0(_x0), y0(_u0), y1(_du0) {}
  virtual ~RK4() = default;

  void run_const_step(size_t n = 100, const LD& step = 0.001, const LD& accuracy = 1e1,
           const LD& b = INFINITY, const std::pair<double, double>& parameters = { 1, 1 })
  {
    if (!y.empty())
    {
      y.clear();
      y2.clear();
      dy.clear();
      dy2.clear();
      estimate.clear();
      c.clear();
    }
    LD x = x0;
    LD y = y0;
    LD y1 = this->y1;
    LD y2 = y0;
    LD y21 = this->y1;
    LD s = NULL;

    for (size_t i = 0; i < n && abs(x) < b; ++i)
    {
      this->y.emplace_back(x, y);
      this->dy.emplace_back(x, y1);
      this->y2.emplace_back(x, y2);
      this->dy2.emplace_back(x, y21);
      this->estimate.push_back(s);
      y2 = y;
      y21 = y1;

      auto kq = this->k(x, y1, y, step, parameters);
      y += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y1 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      kq = this->k(x, y21, y2, step / 2.0, parameters);
      y2 += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y21 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      kq = this->k(x + step / 2.0, y21, y2, step / 2.0, parameters);
      y2 += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y21 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      s = (y2 - y1) / 15.0;
      x += step;
      if (fabs(y1) > accuracy || fabs(y2) > accuracy || isnan(s))
        break;
    }
  }

  std::vector<LD> run_non_const_step(const size_t& n = 100, const LD& step = 0.01,
                                    const LD& epsilon = 1e-6, const LD& accuracy = 1e1,
                                    const LD& b = INFINITY, const std::pair<double, double>& parameters = { NULL, NULL }, const LD ksi = 0)
  {
    if (!y.empty())
    {
      y.clear();
      y2.clear();
      dy.clear();
      dy2.clear();
      estimate.clear();
      c.clear();
    }
    LD x = x0;
    LD y = y0;
    LD y1 = this->y1;
    LD y2 = y0;
    LD y21 = this->y1;
    LD s = NULL;

    std::vector<LD> steps{ step };
    this->y.emplace_back(x, y);
    this->dy.emplace_back(x, y1);
    this->y2.emplace_back(x, y2);
    this->dy2.emplace_back(x, y21);
    this->estimate.push_back(s);
    c.emplace_back(NULL, NULL);

    for (size_t i = 0; i < n && abs(x + steps[i]) < b; ++i)
    {
      if (x > b - ksi)
        break;
      y2 = y;
      y21 = y1;

      auto kq = this->k(x, y1, y, steps[i], parameters);
      y += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y1 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      kq = this->k(x, y21, y2, steps[i] / 2.0, parameters);
      y2 += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y21 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      kq = this->k(x + steps[i] / 2.0, y21, y2, steps[i] / 2.0, parameters);
      y2 += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y21 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      s = (y - y2) / 15.0;
      if (fabs(s) > epsilon)
      {
        steps[i] /= 2.0;
        y = this->y[i].second;
        y1 = this->dy[i].second;
        c[i].first += 1;
        --i;
        continue;
      }
      else if (fabs(s) > epsilon / 32.0 && fabs(s) - epsilon < 1e-32)
      {
        steps.push_back(steps[i]);
      }
      else
      {
        steps.push_back(steps[i] * 2.0);
        c[i].second += 1;
      }
      x += steps[i];
      if (fabs(y) > accuracy || fabs(y2) > accuracy)
        break;
      if(fabs(y1) > b)
        break;
      this->y.emplace_back(x, y);
      this->y2.emplace_back(x, y2);
      this->dy.emplace_back(x, y1);
      this->dy2.emplace_back(x, y21);
      estimate.push_back(fabs(s) * 16);
      c.emplace_back(NULL, NULL);
    }
    if (x < b - ksi && fabs(y) < accuracy && fabs(y2) < accuracy && steps.size() < n)
    {
      steps.push_back(steps[steps.size() - 1] / 2.0);
      auto kq = this->k(x, y1, y, steps[steps.size() - 1], parameters);
      y += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y1 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      kq = this->k(x, y21, y2, steps[steps.size() - 1] / 2.0, parameters);
      y2 += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y21 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      kq = this->k(x + steps[steps.size() - 1] / 2.0, y21, y2, steps[steps.size() - 1] / 2.0, parameters);
      y2 += (kq.first[0] + 2 * kq.first[1] + 2 * kq.first[2] + kq.first[3]) / 6.0;
      y21 += (kq.second[0] + 2 * kq.second[1] + 2 * kq.second[2] + kq.second[3]) / 6.0;

      s = (y - y2) / 15.0;
      x += steps[steps.size() - 1];
      this->y.emplace_back(x, y);
      this->y2.emplace_back(x, y2);
      this->dy.emplace_back(x, y1);
      this->dy2.emplace_back(x, y21);
      estimate.push_back(fabs(s) * 16);
      c.emplace_back(NULL, NULL);
    }
    return steps;
  }

public:
  const VECTOR_PAIR& get_y() const
  {
    return y;
  }
  const VECTOR_PAIR& get_y2() const
  {
    return y2;
  }
  const VECTOR_PAIR& get_dy() const
  {
    return dy;
  }

  const VECTOR_PAIR& get_dy2() const
  {
    return dy2;
  }

  const std::vector<std::pair<int, int>>& get_c() const
  {
    return c;
  }

  const std::vector<LD>& get_estimates() const
  {
    return estimate;
  }

  virtual const VECTOR_PAIR& get_anal_solution()
  {
    throw "The DE can't solved with default analytic methods";
  };

protected:
  virtual LD f1(const LD& x, const LD& dy,
                const LD& y, const std::pair<double, double>& parameters) = NULL;

  virtual LD f2(const LD& x, const LD& y1, const LD& y) = NULL;

  PAIR_VEC k(const LD& x, const LD& y1, const LD& y,
             const LD& step, const std::pair<double, double>& parameters)
  {
    const LD k1 = step * f2(x, y1, y), m1 = step * f1(x, y1, y, parameters),
             k2 = step * f2(x + step / 2.0, y1 + m1 / 2.0, y + k1 / 2.0), m2 = step * f1(x + step / 2.0, y1 + m1 / 2.0, y + k1 / 2.0, parameters),
             k3 = step * f2(x + step / 2.0, y1 + m2 / 2.0, y + k2 / 2.0), m3 = step * f1(x + step / 2.0, y1 + m2 / 2.0, y + k2 / 2.0, parameters),
             k4 = step * f2(x + step, y1 + m3, y + k3), m4 = step * f1(x + step, y1 + m3, y + k3, parameters);
    return PAIR_VEC{ std::vector<LD>{k1, k2, k3, k4}, std::vector<LD>{m1, m2, m3, m4} };
  }


protected:
  LD x0;
  LD y0;
  LD y1;

  VECTOR_PAIR dy;
  VECTOR_PAIR y;

  VECTOR_PAIR dy2;
  VECTOR_PAIR y2;

  std::vector<LD> estimate;
  std::vector<std::pair<int, int>> c;

};

class RK4_main2 : public RK4
{
public:
  RK4_main2(const LD& _x0 = NULL, const LD& _u0 = 1.0,
    const LD& _du0 = 1.0) : RK4(_x0, _u0, _du0)
  {}
  RK4_main2(const RK4_main2& cp) = default;
  ~RK4_main2() override = default;

protected:
  LD f1(const LD& x, const LD& dy,
                const LD& y, const std::pair<double, double>& parameters) override
  {
    return -(dy * dy * parameters.first + y * parameters.second);
  }

  LD f2(const LD& x, const LD& y1, const LD& y) override
  {
    return y1;
  }
};

class RK4_main1 : public RK4
{
public:
  RK4_main1(const LD& _x0 = NULL, const LD& _u0 = 1.0) : RK4(_x0, _u0, NULL)
  {}
  RK4_main1(const RK4_main1& cp) = default;
  ~RK4_main1() override = default;
protected:
  LD f1(const LD& x, const LD& dy,
        const LD& y, const std::pair<double, double>& parameters) override
  {
    return NULL;
  }

  LD f2(const LD& x, const LD& y1, const LD& y) override
  {
    return pow(y, 2) / pow(1 + pow(x, 2), 1.0 / 3.0) + y - pow(y, 3)*sin(10 * x);
  }
};

class RK4_test1 : public RK4
{
public:
  RK4_test1(const LD& _x0 = NULL, const LD& _u0 = 1.0) : RK4(_x0, _u0, NULL), coeff(_u0 / exp(-3.0 / 2.0 * _x0))
  {}
  RK4_test1(const RK4_test1& cp) = default;
  ~RK4_test1() override = default;

  const VECTOR_PAIR& get_anal_solution() override
  {
    enter_solution();
    return anal_sol;
  }

private:
  void enter_solution()
  {
    for (size_t i = 0; i < y.size(); ++i)
    {
      anal_sol.push_back({ y[i].first, true_func(y[i].first) });
    }
  }

protected:
  LD f1(const LD& x, const LD& dy,
    const LD& y, const std::pair<double, double>& parameters) override
  {
    return NULL;
  }

  LD f2(const LD& x, const LD& y1, const LD& y) override
  {
    return -3.0 / 2.0 * y;
  }

  LD true_func(const LD& x) const
  {
    return coeff * exp(-3.0 / 2.0 * x);
  }
private:
  VECTOR_PAIR anal_sol;
  LD coeff;
};
