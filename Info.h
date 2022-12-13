#pragma once
#include <sstream>
#include <string>

namespace firstlab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	#ifndef LD
	  #define LD long double
	#endif

	struct Node
	{
		LD x_last, u_last, olp_max, x_olp_max, global_estimate, x_global_estimate = -1,
			step_max, x_step_max, step_min, x_step_min;
		size_t step_mult, step_split, n_last;
	};


	public ref class Info : public System::Windows::Forms::Form
	{
	public:
		Info(const Node* tmp)
		{
			InitializeComponent();
			std::string str_res_tmp = "Result: \nSteps done: " + to_string(tmp->n_last) + '\n' +
				"Last value: " + to_string(tmp->u_last) +
				" in x: " + to_string(tmp->x_last) + '\n' +
				"Max mark local estimate (V^ - V) * 16 / 15: " +
				to_string(tmp->olp_max) + " â " + to_string(tmp->x_olp_max) + '\n' +
				"Max step: " + to_string(tmp->step_max) + " in " + to_string(tmp->x_step_max) + '\n' +
				"Min step: " + to_string(tmp->step_min) + " in " + to_string(tmp->x_step_min) + '\n' +
				"Number Step*2: " + to_string(tmp->step_mult) +
				" Number step split 2: " + to_string(tmp->step_split) + "\n";
			if (tmp->x_global_estimate != -1)
			{
				str_res_tmp += "Max global estimate in test task: " + to_string(tmp->global_estimate) +
					             " in " + to_string(tmp->x_global_estimate);
			}
			String^ str_res = gcnew String(str_res_tmp.c_str());
			label1->Text = str_res;
		}
	private: template <typename T>
		std::string to_string(T const& value)
		{
			std::stringstream sstr;
			sstr << value;
			return sstr.str();
		}
	protected:
		~Info()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(64, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 21);
			this->label1->TabIndex = 0;
			// 
			// Info
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(588, 476);
			this->Controls->Add(this->label1);
			this->Name = L"Info";
			this->ShowIcon = false;
			this->Text = L"Info";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
