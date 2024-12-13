#pragma once
#include "..\TQue\TQueue.h"
#include <random>

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	  //graphics
	  //ptn
	  //точки
	  const float X;
	  const float Y;
	  const float WIDTH;
	  const float HIGH;
	  
	  Pen^ blue;
	  Pen^ background;
	  Graphics^ gr;

	  TQueue<double>* queue;
	  double P, Q;
	  int countFull, countEmpty, countPush, countPop;

	  int maxSize, startElCount;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ labelStat;
	private: System::Windows::Forms::TextBox^ textBoxCount;


	public:
		MyForm(void) : X(40), Y(300), WIDTH(295), HIGH(295)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			gr = CreateGraphics();
			blue = gcnew Pen(Color::Blue, 20.0f);
			background = gcnew Pen(this->BackColor, 20.0f);

			queue = NULL;
			countFull = 0;
			countEmpty = 0;
			countPush = 0;
			countPop = 0;
			P = 0.5;
			Q = 0.5;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxPush;
	private: System::Windows::Forms::TextBox^ textBoxPop;
	private: System::Windows::Forms::TextBox^ textBoxLength;



	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Button^ buttonStart;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		  this->components = (gcnew System::ComponentModel::Container());
		  this->label1 = (gcnew System::Windows::Forms::Label());
		  this->label2 = (gcnew System::Windows::Forms::Label());
		  this->label3 = (gcnew System::Windows::Forms::Label());
		  this->textBoxPush = (gcnew System::Windows::Forms::TextBox());
		  this->textBoxPop = (gcnew System::Windows::Forms::TextBox());
		  this->textBoxLength = (gcnew System::Windows::Forms::TextBox());
		  this->buttonStop = (gcnew System::Windows::Forms::Button());
		  this->buttonStart = (gcnew System::Windows::Forms::Button());
		  this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		  this->label4 = (gcnew System::Windows::Forms::Label());
		  this->textBoxCount = (gcnew System::Windows::Forms::TextBox());
		  this->labelStat = (gcnew System::Windows::Forms::Label());
		  this->SuspendLayout();
		  // 
		  // label1
		  // 
		  this->label1->AutoSize = true;
		  this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
		  this->label1->Location = System::Drawing::Point(34, 29);
		  this->label1->Name = L"label1";
		  this->label1->Size = System::Drawing::Size(212, 25);
		  this->label1->TabIndex = 0;
		  this->label1->Text = L"Вероятность вставки";
		  // 
		  // label2
		  // 
		  this->label2->AutoSize = true;
		  this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
		  this->label2->Location = System::Drawing::Point(34, 72);
		  this->label2->Name = L"label2";
		  this->label2->Size = System::Drawing::Size(249, 25);
		  this->label2->TabIndex = 1;
		  this->label2->Text = L"Вероятность извлечения";
		  // 
		  // label3
		  // 
		  this->label3->AutoSize = true;
		  this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
		  this->label3->Location = System::Drawing::Point(34, 113);
		  this->label3->Name = L"label3";
		  this->label3->Size = System::Drawing::Size(294, 25);
		  this->label3->TabIndex = 2;
		  this->label3->Text = L"Максимальная длина очереди";
		  // 
		  // textBoxPush
		  // 
		  this->textBoxPush->Location = System::Drawing::Point(381, 33);
		  this->textBoxPush->Name = L"textBoxPush";
		  this->textBoxPush->Size = System::Drawing::Size(75, 22);
		  this->textBoxPush->TabIndex = 3;
		  this->textBoxPush->Text = L"0,5";
		  // 
		  // textBoxPop
		  // 
		  this->textBoxPop->Location = System::Drawing::Point(381, 74);
		  this->textBoxPop->Name = L"textBoxPop";
		  this->textBoxPop->Size = System::Drawing::Size(75, 22);
		  this->textBoxPop->TabIndex = 4;
		  this->textBoxPop->Text = L"0,5";
		  // 
		  // textBoxLength
		  // 
		  this->textBoxLength->Location = System::Drawing::Point(381, 115);
		  this->textBoxLength->Name = L"textBoxLength";
		  this->textBoxLength->Size = System::Drawing::Size(75, 22);
		  this->textBoxLength->TabIndex = 5;
		  this->textBoxLength->Text = L"1000";
		  // 
		  // buttonStop
		  // 
		  this->buttonStop->Location = System::Drawing::Point(287, 276);
		  this->buttonStop->Name = L"buttonStop";
		  this->buttonStop->Size = System::Drawing::Size(169, 38);
		  this->buttonStop->TabIndex = 6;
		  this->buttonStop->Text = L"Стоп";
		  this->buttonStop->UseVisualStyleBackColor = true;
		  this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
		  // 
		  // buttonStart
		  // 
		  this->buttonStart->Location = System::Drawing::Point(39, 276);
		  this->buttonStart->Name = L"buttonStart";
		  this->buttonStart->Size = System::Drawing::Size(169, 38);
		  this->buttonStart->TabIndex = 7;
		  this->buttonStart->Text = L"Старт";
		  this->buttonStart->UseVisualStyleBackColor = true;
		  this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStart_Click);
		  // 
		  // timer1
		  // 
		  this->timer1->Interval = 10;
		  this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
		  // 
		  // label4
		  // 
		  this->label4->AutoSize = true;
		  this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
		  this->label4->Location = System::Drawing::Point(34, 158);
		  this->label4->Name = L"label4";
		  this->label4->Size = System::Drawing::Size(336, 25);
		  this->label4->TabIndex = 8;
		  this->label4->Text = L"Начальное количество елементов";
		  // 
		  // textBoxCount
		  // 
		  this->textBoxCount->Location = System::Drawing::Point(381, 158);
		  this->textBoxCount->Name = L"textBoxCount";
		  this->textBoxCount->Size = System::Drawing::Size(75, 22);
		  this->textBoxCount->TabIndex = 9;
		  this->textBoxCount->Text = L"100";
		  // 
		  // labelStat
		  // 
		  this->labelStat->AutoSize = true;
		  this->labelStat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->labelStat->Location = System::Drawing::Point(39, 203);
		  this->labelStat->Name = L"labelStat";
		  this->labelStat->Size = System::Drawing::Size(114, 20);
		  this->labelStat->TabIndex = 10;
		  this->labelStat->Text = L"Статистика:";
		  // 
		  // MyForm
		  // 
		  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		  this->ClientSize = System::Drawing::Size(492, 753);
		  this->Controls->Add(this->labelStat);
		  this->Controls->Add(this->textBoxCount);
		  this->Controls->Add(this->label4);
		  this->Controls->Add(this->buttonStart);
		  this->Controls->Add(this->buttonStop);
		  this->Controls->Add(this->textBoxLength);
		  this->Controls->Add(this->textBoxPop);
		  this->Controls->Add(this->textBoxPush);
		  this->Controls->Add(this->label3);
		  this->Controls->Add(this->label2);
		  this->Controls->Add(this->label1);
		  this->Name = L"MyForm";
		  this->Text = L"MyForm";
		  this->ResumeLayout(false);
		  this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void drawQueue() {
	  float start = 360.0 * ((double)queue->getHead() / (double)queue->getMaxElCount());
	  float finish = 360.0 * ((double)queue->getElCount() / (double)queue->getMaxElCount());
	  
	  gr->DrawArc(blue, X, Y, WIDTH, HIGH, start, finish);
	  //gr->DrawArc(blue, 40.0, 350.0, 250.0, 250.0, start, finish);
	}

	private: System::Void drawBackground() {
	  float start = 360.0 * ((double)queue->getHead() / (double)queue->getMaxElCount());
	  float finish = 360.0 * ((double)queue->getElCount() / (double)queue->getMaxElCount());

	  gr->DrawArc(background, X, Y, WIDTH, HIGH, start, finish);
	}
	 
	private: System::Void clearCircle() {
	  gr->DrawArc(background, X, Y, WIDTH, HIGH, 0.0, 360.0);
	}
	private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	  //инициализация очереди из полей
	  timer1->Stop();
	  clearCircle();

	  countPop = 0;
	  countPush = 0;
	  countEmpty = 0;
	  countFull = 0;

	  P = System::Double::Parse(textBoxPush->Text);
	  Q = System::Double::Parse(textBoxPop->Text);
	  maxSize = System::Int32::Parse(textBoxLength->Text);
	  startElCount = System::Int32::Parse(textBoxCount->Text);
	  
	  if (queue != NULL) {
		delete queue;
	  }
	  queue = new TQueue<double>(maxSize);
	  for (int i = 0; i < startElCount; i++)
		queue->push(0.0);
	  drawQueue();
	 /* Pen^ p = gcnew Pen(Color::Aqua);
	  gr->DrawArc(p,100, 100, 100, 100, 0, 100);*/
	  timer1->Start();
	}

	private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	  timer1->Stop();
	  System::String^ statText = "Статистика:\n вставок - " + countPush + "; вставок в полную очередь - " + countFull + ";\n" +
											  "извлечений - " + countPop + "; извлечений из пустой - " + countEmpty;
	  labelStat->Text = statText;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
	  drawBackground();
	  
	  std::random_device rd;
	  std::mt19937 gen(rd());
	  std::uniform_real_distribution<> rdis(0, 1);

	  double p = rdis(gen);
	  double q = rdis(gen);

	  if (p < P)
	  {
		if (!queue->isFull())
		{
		  queue->push(0.0);
		  countPush++;
		}
		else
		  countFull++;
	  }

	  if (q < Q)
	  {
		if (!queue->isEmpty())
		{
		  queue->pop();
		  countPop++;
		}
		else
		  countEmpty++;
	  }

	  drawQueue();
	}

};
}
