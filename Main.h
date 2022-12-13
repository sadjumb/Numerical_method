#pragma once
#include "RK4.h"
#include "Info.h"

namespace firstlab {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			main_rk = nullptr;
			res = nullptr;
			a = nullptr;
			InitializeComponent();
		}

	protected:
		~Main()
		{
			if (main_rk)
			{
				delete main_rk;
				main_rk = nullptr;
			}

		  if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: RK4* main_rk;
	private: Node* res;
	private: Info^ a;
	private: System::Windows::Forms::Button^ button_test;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TextBox^ textBox_du0;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox_ksi;
	private: System::Windows::Forms::TextBox^ textBox_eps;
	private: System::Windows::Forms::TextBox^ textBox_step;
	private: System::Windows::Forms::TextBox^ textBox_b;
	private: System::Windows::Forms::TextBox^ textBox_N;
	private: System::Windows::Forms::TextBox^ textBox_x0;
	private: System::Windows::Forms::TextBox^ textBox_u0;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RadioButton^ radioButton_test;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ radioButton_main1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RadioButton^ radioButton_control_Step;
	private: System::Windows::Forms::RadioButton^ radioButton_without;
	private: System::Windows::Forms::RadioButton^ radioButton_main2;
	private: System::Windows::Forms::TextBox^ textBox_beta;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox_alpha;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::CheckBox^ checkBox_Refresh;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::RadioButton^ radioButton_VDV;

	private: System::Windows::Forms::RadioButton^ radioButton_VX;
	private: System::Windows::Forms::RadioButton^ radioButton_DVX;
	private: System::Windows::Forms::Button^ button_runInfo;
	private: System::Windows::Forms::TextBox^ textBox_accuracy;

	private: System::Windows::Forms::Label^ label14;



	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_accuracy = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button_runInfo = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_VDV = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_VX = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_DVX = (gcnew System::Windows::Forms::RadioButton());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox_beta = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox_alpha = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_control_Step = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_without = (gcnew System::Windows::Forms::RadioButton());
			this->button_test = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_du0 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_ksi = (gcnew System::Windows::Forms::TextBox());
			this->textBox_eps = (gcnew System::Windows::Forms::TextBox());
			this->textBox_step = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->textBox_N = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x0 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_u0 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_main2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_test = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_main1 = (gcnew System::Windows::Forms::RadioButton());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->checkBox_Refresh = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox_accuracy);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->button_runInfo);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->textBox_beta);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->textBox_alpha);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->button_test);
			this->groupBox1->Controls->Add(this->pictureBox3);
			this->groupBox1->Controls->Add(this->textBox_du0);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->pictureBox2);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Controls->Add(this->textBox_ksi);
			this->groupBox1->Controls->Add(this->textBox_eps);
			this->groupBox1->Controls->Add(this->textBox_step);
			this->groupBox1->Controls->Add(this->textBox_b);
			this->groupBox1->Controls->Add(this->textBox_N);
			this->groupBox1->Controls->Add(this->textBox_x0);
			this->groupBox1->Controls->Add(this->textBox_u0);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(2050, 249);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parametrs task";
			// 
			// textBox_accuracy
			// 
			this->textBox_accuracy->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_accuracy->Location = System::Drawing::Point(250, 124);
			this->textBox_accuracy->Name = L"textBox_accuracy";
			this->textBox_accuracy->Size = System::Drawing::Size(80, 26);
			this->textBox_accuracy->TabIndex = 35;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(179, 124);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(65, 23);
			this->label14->TabIndex = 34;
			this->label14->Text = L"max U";
			// 
			// button_runInfo
			// 
			this->button_runInfo->Location = System::Drawing::Point(835, 185);
			this->button_runInfo->Name = L"button_runInfo";
			this->button_runInfo->Size = System::Drawing::Size(142, 37);
			this->button_runInfo->TabIndex = 33;
			this->button_runInfo->Text = L"Run result";
			this->button_runInfo->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->radioButton_VDV);
			this->groupBox4->Controls->Add(this->radioButton_VX);
			this->groupBox4->Controls->Add(this->radioButton_DVX);
			this->groupBox4->Location = System::Drawing::Point(1261, 142);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(188, 107);
			this->groupBox4->TabIndex = 25;
			this->groupBox4->TabStop = false;
			// 
			// radioButton_VDV
			// 
			this->radioButton_VDV->AutoSize = true;
			this->radioButton_VDV->Location = System::Drawing::Point(28, 76);
			this->radioButton_VDV->Name = L"radioButton_VDV";
			this->radioButton_VDV->Size = System::Drawing::Size(68, 24);
			this->radioButton_VDV->TabIndex = 24;
			this->radioButton_VDV->TabStop = true;
			this->radioButton_VDV->Text = L"V(dV)";
			this->radioButton_VDV->UseVisualStyleBackColor = true;
			// 
			// radioButton_VX
			// 
			this->radioButton_VX->AutoSize = true;
			this->radioButton_VX->Location = System::Drawing::Point(28, 16);
			this->radioButton_VX->Name = L"radioButton_VX";
			this->radioButton_VX->Size = System::Drawing::Size(55, 24);
			this->radioButton_VX->TabIndex = 22;
			this->radioButton_VX->TabStop = true;
			this->radioButton_VX->Text = L"V(x)";
			this->radioButton_VX->UseVisualStyleBackColor = true;
			// 
			// radioButton_DVX
			// 
			this->radioButton_DVX->AutoSize = true;
			this->radioButton_DVX->Location = System::Drawing::Point(28, 46);
			this->radioButton_DVX->Name = L"radioButton_DVX";
			this->radioButton_DVX->Size = System::Drawing::Size(68, 24);
			this->radioButton_DVX->TabIndex = 23;
			this->radioButton_DVX->TabStop = true;
			this->radioButton_DVX->Text = L"dV (x)";
			this->radioButton_DVX->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(1184, 137);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(56, 20);
			this->label13->TabIndex = 32;
			this->label13->Text = L"main 2";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(798, 108);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(56, 20);
			this->label12->TabIndex = 31;
			this->label12->Text = L"main 1";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(505, 108);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(40, 20);
			this->label11->TabIndex = 30;
			this->label11->Text = L"Test";
			// 
			// textBox_beta
			// 
			this->textBox_beta->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_beta->Location = System::Drawing::Point(250, 92);
			this->textBox_beta->Name = L"textBox_beta";
			this->textBox_beta->Size = System::Drawing::Size(80, 26);
			this->textBox_beta->TabIndex = 29;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(179, 95);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(44, 23);
			this->label10->TabIndex = 28;
			this->label10->Text = L"beta";
			// 
			// textBox_alpha
			// 
			this->textBox_alpha->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_alpha->Location = System::Drawing::Point(250, 60);
			this->textBox_alpha->Name = L"textBox_alpha";
			this->textBox_alpha->Size = System::Drawing::Size(80, 26);
			this->textBox_alpha->TabIndex = 27;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(179, 63);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(54, 23);
			this->label9->TabIndex = 26;
			this->label9->Text = L"alpha";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton_control_Step);
			this->groupBox3->Controls->Add(this->radioButton_without);
			this->groupBox3->Location = System::Drawing::Point(269, 155);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(188, 87);
			this->groupBox3->TabIndex = 25;
			this->groupBox3->TabStop = false;
			// 
			// radioButton_control_Step
			// 
			this->radioButton_control_Step->AutoSize = true;
			this->radioButton_control_Step->Location = System::Drawing::Point(28, 24);
			this->radioButton_control_Step->Name = L"radioButton_control_Step";
			this->radioButton_control_Step->Size = System::Drawing::Size(146, 24);
			this->radioButton_control_Step->TabIndex = 22;
			this->radioButton_control_Step->TabStop = true;
			this->radioButton_control_Step->Text = L"With control step";
			this->radioButton_control_Step->UseVisualStyleBackColor = true;
			// 
			// radioButton_without
			// 
			this->radioButton_without->AutoSize = true;
			this->radioButton_without->Location = System::Drawing::Point(28, 54);
			this->radioButton_without->Name = L"radioButton_without";
			this->radioButton_without->Size = System::Drawing::Size(134, 24);
			this->radioButton_without->TabIndex = 23;
			this->radioButton_without->TabStop = true;
			this->radioButton_without->Text = L"Without control";
			this->radioButton_without->UseVisualStyleBackColor = true;
			// 
			// button_test
			// 
			this->button_test->Location = System::Drawing::Point(657, 185);
			this->button_test->Name = L"button_test";
			this->button_test->Size = System::Drawing::Size(142, 37);
			this->button_test->TabIndex = 21;
			this->button_test->Text = L"Run";
			this->button_test->UseVisualStyleBackColor = true;
			this->button_test->Click += gcnew System::EventHandler(this, &Main::button_test_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1074, 14);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(289, 120);
			this->pictureBox3->TabIndex = 18;
			this->pictureBox3->TabStop = false;
			// 
			// textBox_du0
			// 
			this->textBox_du0->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_du0->Location = System::Drawing::Point(250, 28);
			this->textBox_du0->Name = L"textBox_du0";
			this->textBox_du0->Size = System::Drawing::Size(80, 26);
			this->textBox_du0->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(179, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 23);
			this->label8->TabIndex = 16;
			this->label8->Text = L"du0";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(625, 14);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(425, 79);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(463, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(156, 91);
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// textBox_ksi
			// 
			this->textBox_ksi->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_ksi->Location = System::Drawing::Point(83, 220);
			this->textBox_ksi->Name = L"textBox_ksi";
			this->textBox_ksi->Size = System::Drawing::Size(80, 26);
			this->textBox_ksi->TabIndex = 13;
			// 
			// textBox_eps
			// 
			this->textBox_eps->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_eps->Location = System::Drawing::Point(83, 188);
			this->textBox_eps->Name = L"textBox_eps";
			this->textBox_eps->Size = System::Drawing::Size(80, 26);
			this->textBox_eps->TabIndex = 12;
			// 
			// textBox_step
			// 
			this->textBox_step->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_step->Location = System::Drawing::Point(83, 156);
			this->textBox_step->Name = L"textBox_step";
			this->textBox_step->Size = System::Drawing::Size(80, 26);
			this->textBox_step->TabIndex = 11;
			// 
			// textBox_b
			// 
			this->textBox_b->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_b->Location = System::Drawing::Point(83, 124);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(80, 26);
			this->textBox_b->TabIndex = 10;
			// 
			// textBox_N
			// 
			this->textBox_N->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_N->Location = System::Drawing::Point(83, 92);
			this->textBox_N->Name = L"textBox_N";
			this->textBox_N->Size = System::Drawing::Size(80, 26);
			this->textBox_N->TabIndex = 9;
			// 
			// textBox_x0
			// 
			this->textBox_x0->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_x0->Location = System::Drawing::Point(83, 60);
			this->textBox_x0->Name = L"textBox_x0";
			this->textBox_x0->Size = System::Drawing::Size(80, 26);
			this->textBox_x0->TabIndex = 8;
			// 
			// textBox_u0
			// 
			this->textBox_u0->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_u0->Location = System::Drawing::Point(83, 28);
			this->textBox_u0->Name = L"textBox_u0";
			this->textBox_u0->Size = System::Drawing::Size(80, 26);
			this->textBox_u0->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(7, 223);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 23);
			this->label7->TabIndex = 6;
			this->label7->Text = L"ksi";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(7, 191);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 23);
			this->label6->TabIndex = 5;
			this->label6->Text = L"epsilon";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(7, 159);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 23);
			this->label5->TabIndex = 4;
			this->label5->Text = L"step";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(7, 127);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(20, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"b";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(7, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"N";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(7, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"x0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(7, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"u0";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton_main2);
			this->groupBox2->Controls->Add(this->radioButton_test);
			this->groupBox2->Controls->Add(this->radioButton_main1);
			this->groupBox2->Location = System::Drawing::Point(463, 135);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(188, 107);
			this->groupBox2->TabIndex = 24;
			this->groupBox2->TabStop = false;
			// 
			// radioButton_main2
			// 
			this->radioButton_main2->AutoSize = true;
			this->radioButton_main2->Location = System::Drawing::Point(28, 76);
			this->radioButton_main2->Name = L"radioButton_main2";
			this->radioButton_main2->Size = System::Drawing::Size(74, 24);
			this->radioButton_main2->TabIndex = 24;
			this->radioButton_main2->TabStop = true;
			this->radioButton_main2->Text = L"Main 2";
			this->radioButton_main2->UseVisualStyleBackColor = true;
			// 
			// radioButton_test
			// 
			this->radioButton_test->AutoSize = true;
			this->radioButton_test->Location = System::Drawing::Point(28, 16);
			this->radioButton_test->Name = L"radioButton_test";
			this->radioButton_test->Size = System::Drawing::Size(58, 24);
			this->radioButton_test->TabIndex = 22;
			this->radioButton_test->TabStop = true;
			this->radioButton_test->Text = L"Test";
			this->radioButton_test->UseVisualStyleBackColor = true;
			// 
			// radioButton_main1
			// 
			this->radioButton_main1->AutoSize = true;
			this->radioButton_main1->Location = System::Drawing::Point(28, 46);
			this->radioButton_main1->Name = L"radioButton_main1";
			this->radioButton_main1->Size = System::Drawing::Size(74, 24);
			this->radioButton_main1->TabIndex = 23;
			this->radioButton_main1->TabStop = true;
			this->radioButton_main1->Text = L"Main 1";
			this->radioButton_main1->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			chartArea1->AxisX->Title = L"X";
			chartArea1->AxisY->Title = L"U";
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Right;
			legend1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			legend1->IsTextAutoFit = false;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend1->Name = L"Legend1";
			legend1->Position->Auto = false;
			legend1->Position->Height = 6.157636F;
			legend1->Position->Width = 18.61648F;
			legend1->Position->X = 78.38352F;
			legend1->Position->Y = 3;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(1066, 249);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Red;
			series1->CustomProperties = L"IsXAxisQuantitative=True";
			series1->Legend = L"Legend1";
			series1->LegendText = L"V(x) - численное решение";
			series1->Name = L"Series1";
			series1->YValuesPerPoint = 15;
			series2->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDotDot;
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::DodgerBlue;
			series2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series2->Legend = L"Legend1";
			series2->Name = L"U(x) - true solution for Test";
			series2->ShadowColor = System::Drawing::SystemColors::MenuText;
			series2->YValuesPerPoint = 15;
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(984, 813);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 249);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(1060, 813);
			this->dataGridView1->TabIndex = 2;
			// 
			// checkBox_Refresh
			// 
			this->checkBox_Refresh->AutoSize = true;
			this->checkBox_Refresh->Location = System::Drawing::Point(1074, 255);
			this->checkBox_Refresh->Name = L"checkBox_Refresh";
			this->checkBox_Refresh->Size = System::Drawing::Size(90, 17);
			this->checkBox_Refresh->TabIndex = 30;
			this->checkBox_Refresh->Text = L"Refresh chart";
			this->checkBox_Refresh->UseVisualStyleBackColor = true;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2050, 1062);
			this->Controls->Add(this->checkBox_Refresh);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox1);
			this->MaximumSize = System::Drawing::Size(2066, 1101);
			this->MinimumSize = System::Drawing::Size(2066, 1101);
			this->Name = L"Main";
			this->Text = L"Main";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: auto parse_parameters()
	{
		std::vector<LD> parametrs{ Double::Parse(textBox_u0->Text), Double::Parse(textBox_x0->Text),
															 Double::Parse(textBox_N->Text), Double::Parse(textBox_b->Text),
															 Double::Parse(textBox_step->Text), Double::Parse(textBox_eps->Text),
															 Double::Parse(textBox_ksi->Text) };
	  textBox_du0->Text != "" ? parametrs.push_back(Double::Parse(textBox_du0->Text)) : parametrs.push_back(0);
		textBox_alpha->Text != "" ? parametrs.push_back(Double::Parse(textBox_alpha->Text)) : parametrs.push_back(0);
		textBox_beta->Text != "" ? parametrs.push_back(Double::Parse(textBox_beta->Text)) : parametrs.push_back(0);

		return parametrs;
	}// 0 - u0, 1 - x0, 2 - N, 3 - b, 4 - step, 5 - eps, 6 - ksi, 7 - du0, 8 - alpha, 9 - beta
	private:System::Void enter_column(const std::vector<std::string>& cells)
	{
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		dataGridView1->Refresh();
		dataGridView1->ColumnCount = cells.size();
		dataGridView1->RowCount = main_rk->get_y().size() + 3;
		for (size_t i = 0; i < cells.size(); ++i)
		{
			dataGridView1->Rows[0]->Cells[i]->Value = gcnew String(cells[i].c_str());
		}
	}

	private: System::Void button_test_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if(a != nullptr)
		  a->Close();
		if (textBox_u0->Text == "" || textBox_x0->Text == "" || textBox_N->Text == "" || 
			  textBox_b->Text == "" || textBox_step->Text == "" ||
		    textBox_eps->Text == "" || textBox_ksi->Text == "")
		{
			MessageBox::Show("Please input all data");
			return;
		}
		if (main_rk)
		{
			delete main_rk;
			main_rk = nullptr;
			delete res;
			delete a;
		}

		// Save last trajectory
		if (!checkBox_Refresh->Checked && chart1->Series[0]->Points->Count)
		{
			DataVisualization::Charting::Series^ tmp = gcnew DataVisualization::Charting::Series;
			tmp->ChartType = DataVisualization::Charting::SeriesChartType::Line;
			tmp->YValuesPerPoint = chart1->Series[0]->YValuesPerPoint;

			for (size_t i = 0; i < chart1->Series[0]->Points->Count; ++i)
			  tmp->Points->Add(chart1->Series[0]->Points[i]);

			tmp->Name += System::Convert::ToString(chart1->Series->Count + 1);
			chart1->Series->Add(tmp);
		}
		else
		{
			for(constexpr size_t i = 2; chart1->Series->Count > 2;)
			  chart1->Series->RemoveAt(i);
		}

		chart1->Series[0]->Points->Clear();
		chart1->Series[1]->Points->Clear();
		chart1->Refresh();

		const std::vector<LD> parameters = parse_parameters();
		std::vector<std::string> cells;

		if (!(radioButton_test->Checked || radioButton_main1->Checked || radioButton_main2->Checked))
		{
			MessageBox::Show("Choose Task");
			return;
		}

		if (radioButton_test->Checked)
		{
			main_rk = new RK4_test1(parameters[1], parameters[0]);
			cells = std::vector<std::string>
			{
			"n", "x", "v1", "v2", "v1-v2",
			"OLP", "h", "h/2", "h*2", "U", "|U-V|"
			};
		}
		else if (radioButton_main1->Checked)
		{
			main_rk = new RK4_main1(parameters[1], parameters[0]);
			cells = std::vector<std::string>
			{
			"n", "x", "v1", "v2", "v1-v2",
			"OLP", "h", "h/2", "h*2"
			};
		}
		else
		{
		  if (textBox_alpha->Text == "" || textBox_beta->Text == "" || textBox_du0->Text == "")
		  {
				MessageBox::Show("Enter alpha, beta AND du0");
		    return;
		  }
			if (!(radioButton_DVX->Checked || radioButton_VX->Checked || radioButton_VDV->Checked))
				radioButton_VX->Checked = true;
			main_rk = new RK4_main2(parameters[1], parameters[0], parameters[7]);
		  cells = std::vector<std::string>
			{
			"n", "x", "v1", "v2", "v1-v2",
			"OLP", "h", "h/2", "h*2", "dv", "dv2"
			};
			if(checkBox_Refresh->Checked)
			{
				chart1->Series[1]->Points->Clear();
			}
		}
		
		std::vector<LD> steps;
		std::vector<std::pair<int, int>> c;

		const LD accuracy = textBox_accuracy->Text == "" ? 100 : Double::Parse(textBox_accuracy->Text);

		// Run algorithm
		if (!(radioButton_control_Step->Checked || radioButton_without->Checked))
		{
			MessageBox::Show("Please choose method");
			return;
		}
    if (radioButton_control_Step->Checked)
		{
			steps = main_rk->run_non_const_step(parameters[2], parameters[4], parameters[5],
				                                  accuracy, parameters[3], { parameters[8], parameters[9] }, parameters[6]);
			c = main_rk->get_c();
		}
    else
		{
			main_rk->run_const_step(parameters[2], parameters[4], accuracy, parameters[3], { parameters[8], parameters[9] });
			steps = std::vector<LD>(main_rk->get_dy().size(), parameters[4]);
			c = std::vector<std::pair<int, int>>(steps.size(), { 0, 0 });
		}

		const std::vector<LD>& estimate = main_rk->get_estimates();
		
		const VECTOR_PAIR& sol1 = main_rk->get_y();
		const VECTOR_PAIR& sol2 = main_rk->get_y2();
		

		enter_column(cells);

		int h_mult = 0;
		int h_del = 0;
		LD max_step = steps[0], x_max_step = sol1[0].first;
		LD min_step = steps[0], x_min_step = sol1[0].first;
		LD max_estimate = estimate[0], es_x = sol1[0].first;

		res = new Node;

		// Enter dataGridView
		for (int i = 0; i < sol1.size(); i++)
		{
			dataGridView1->Rows[i + 1]->Cells[0]->Value = i;
			dataGridView1->Rows[i + 1]->Cells[1]->Value = sol1[i].first;
			dataGridView1->Rows[i + 1]->Cells[2]->Value = sol1[i].second;
			dataGridView1->Rows[i + 1]->Cells[3]->Value = sol2[i].second;
			dataGridView1->Rows[i + 1]->Cells[4]->Value = sol1[i].second - sol2[i].second;
			dataGridView1->Rows[i + 1]->Cells[5]->Value = estimate[i];

			if (estimate[i] > max_estimate)
			{
				es_x = sol1[i].first;
				max_estimate = estimate[i];
			}
			dataGridView1->Rows[i + 1]->Cells[6]->Value = steps[i];

			if (steps[i] > max_step)
			{
				max_step = steps[i];
				x_max_step = sol1[i].first;
			}
			if (steps[i] < min_step)
			{
				min_step = steps[i];
				x_min_step = sol1[i].first;
			}

			dataGridView1->Rows[i + 1]->Cells[7]->Value = c[i].first;
			h_mult += c[i].first;

			dataGridView1->Rows[i + 1]->Cells[8]->Value = c[i].second;
			h_del += c[i].second;
			
		}

		res->n_last = sol1.size();
		res->olp_max = max_estimate;
		res->x_olp_max = es_x;
		res->step_max = max_step;
		res->x_step_max = x_max_step;
		res->step_min = min_step;
		res->x_step_min = x_min_step;
		res->step_mult = h_del;
		res->step_split = h_mult;
		res->x_last = sol1[sol1.size() - 1].first;
		res->u_last = sol1[sol1.size() - 1].second;

		if (radioButton_test->Checked || radioButton_main1->Checked ||
			 (radioButton_main2->Checked && radioButton_VX->Checked))
		{
			for (size_t i = 0; i < sol1.size(); ++i)
			  chart1->Series[0]->Points->AddXY(sol1[i].first, sol1[i].second);
		}

	  if (radioButton_test->Checked)
		{
			const VECTOR_PAIR& anal_solution = main_rk->get_anal_solution();
			long double global_max = fabs(anal_solution[0].second - sol1[0].second), x_global_max = sol1[0].first;

			for (size_t i = 0; i < anal_solution.size(); ++i)
			{
				dataGridView1->Rows[i + 1]->Cells[9]->Value = anal_solution[i].second;
				dataGridView1->Rows[i + 1]->Cells[10]->Value = fabs(anal_solution[i].second - sol1[i].second);
				if (fabs(anal_solution[i].second - sol1[i].second) > global_max)
				{
					global_max = fabs(anal_solution[i].second - sol1[i].second);
					x_global_max = sol1[i].first;
				}
				chart1->Series[1]->Points->AddXY(anal_solution[i].first, anal_solution[i].second);
			}
			res->global_estimate = global_max;
			res->x_global_estimate = x_global_max;
		}
		else if (radioButton_main2->Checked)
		{
			const VECTOR_PAIR& dy = main_rk->get_dy();
			const VECTOR_PAIR& dy2 = main_rk->get_dy2();
			for (size_t i = 0; i < dy.size(); ++i)
			{
				dataGridView1->Rows[i + 1]->Cells[9]->Value = dy[i].second;
				dataGridView1->Rows[i + 1]->Cells[10]->Value = dy2[i].second;
			}
			const VECTOR_PAIR& tmp = main_rk->get_dy();
			if (radioButton_DVX->Checked)
			{
				for(size_t i = 0; i < tmp.size(); ++i)
				{
					chart1->Series[0]->Points->AddXY(tmp[i].first, tmp[i].second);
				}
			}
			else if(radioButton_VDV->Checked)
			{
				for (size_t i = 0; i < tmp.size(); ++i)
				{
					chart1->Series[0]->Points->AddXY(tmp[i].second, sol1[i].second);
				}
			}
		}

		a = gcnew Info(res);
		a->Show();
	}
};
}
