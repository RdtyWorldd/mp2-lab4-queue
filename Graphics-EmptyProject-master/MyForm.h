#pragma once
#include <vector>
#include <random>
#include <cmath>
#include "..\TQue\TQueue.h"

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
	
	struct TaskInfo
	{
	  int procCount;
	  int tickCount;
	  int id;
	};

	struct ProcInfo
	{
	  bool isBusy;
	  int taskId;
	  int currentTick;
	  int freeTime;
	};

	public ref class MyForm : public System::Windows::Forms::Form
	{ 
	  std::vector<ProcInfo>* proc;
	  std::vector<TaskInfo>* execution;
	  TQueue<TaskInfo>* taskQueue;

	  int maxProcCount;
	  int minProcCount;
	  int maxTickCount;
	  int minTickCount;

	  int giveTaskCount;
	private: System::Windows::Forms::Panel^ panelProc;
	public:
		MyForm(void)
		{
			InitializeComponent();
	
			proc = new std::vector<ProcInfo>;
			execution = new std::vector<TaskInfo>;
			taskQueue = nullptr;

			maxProcCount = 0;
			minProcCount = 0;
			maxTickCount = 0;
			minTickCount = 0;

			giveTaskCount = 0;
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

	private: System::Windows::Forms::Panel^ panelQueue;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxVector;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxQueueSize;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxMaxTick;
	private: System::Windows::Forms::TextBox^ textBoxMinTick;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxMaxProc;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxMinProc;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ labelCompleted;
	private: System::Windows::Forms::Label^ labelFree;


	private: System::Windows::Forms::Button^ buttonStart;
	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

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
		  this->panelQueue = (gcnew System::Windows::Forms::Panel());
		  this->label1 = (gcnew System::Windows::Forms::Label());
		  this->textBoxVector = (gcnew System::Windows::Forms::TextBox());
		  this->label2 = (gcnew System::Windows::Forms::Label());
		  this->textBoxQueueSize = (gcnew System::Windows::Forms::TextBox());
		  this->label3 = (gcnew System::Windows::Forms::Label());
		  this->textBoxMaxTick = (gcnew System::Windows::Forms::TextBox());
		  this->textBoxMinTick = (gcnew System::Windows::Forms::TextBox());
		  this->label4 = (gcnew System::Windows::Forms::Label());
		  this->textBoxMaxProc = (gcnew System::Windows::Forms::TextBox());
		  this->label5 = (gcnew System::Windows::Forms::Label());
		  this->textBoxMinProc = (gcnew System::Windows::Forms::TextBox());
		  this->label6 = (gcnew System::Windows::Forms::Label());
		  this->labelCompleted = (gcnew System::Windows::Forms::Label());
		  this->labelFree = (gcnew System::Windows::Forms::Label());
		  this->buttonStart = (gcnew System::Windows::Forms::Button());
		  this->buttonStop = (gcnew System::Windows::Forms::Button());
		  this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		  this->panelProc = (gcnew System::Windows::Forms::Panel());
		  this->SuspendLayout();
		  // 
		  // panelQueue
		  // 
		  this->panelQueue->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		  this->panelQueue->Location = System::Drawing::Point(579, 13);
		  this->panelQueue->Name = L"panelQueue";
		  this->panelQueue->Size = System::Drawing::Size(159, 350);
		  this->panelQueue->TabIndex = 1;
		  // 
		  // label1
		  // 
		  this->label1->AutoSize = true;
		  this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label1->Location = System::Drawing::Point(13, 13);
		  this->label1->Name = L"label1";
		  this->label1->Size = System::Drawing::Size(174, 16);
		  this->label1->TabIndex = 2;
		  this->label1->Text = L"Количество процессоров";
		  // 
		  // textBoxVector
		  // 
		  this->textBoxVector->Location = System::Drawing::Point(25, 32);
		  this->textBoxVector->Name = L"textBoxVector";
		  this->textBoxVector->Size = System::Drawing::Size(78, 22);
		  this->textBoxVector->TabIndex = 3;
		  // 
		  // label2
		  // 
		  this->label2->AutoSize = true;
		  this->label2->Location = System::Drawing::Point(13, 66);
		  this->label2->Name = L"label2";
		  this->label2->Size = System::Drawing::Size(116, 16);
		  this->label2->TabIndex = 4;
		  this->label2->Text = L"Размер очереди";
		  // 
		  // textBoxQueueSize
		  // 
		  this->textBoxQueueSize->Location = System::Drawing::Point(25, 85);
		  this->textBoxQueueSize->Name = L"textBoxQueueSize";
		  this->textBoxQueueSize->Size = System::Drawing::Size(78, 22);
		  this->textBoxQueueSize->TabIndex = 5;
		  // 
		  // label3
		  // 
		  this->label3->AutoSize = true;
		  this->label3->Location = System::Drawing::Point(14, 122);
		  this->label3->Name = L"label3";
		  this->label3->Size = System::Drawing::Size(115, 16);
		  this->label3->TabIndex = 6;
		  this->label3->Text = L"Максимум тиков";
		  // 
		  // textBoxMaxTick
		  // 
		  this->textBoxMaxTick->Location = System::Drawing::Point(26, 142);
		  this->textBoxMaxTick->Name = L"textBoxMaxTick";
		  this->textBoxMaxTick->Size = System::Drawing::Size(78, 22);
		  this->textBoxMaxTick->TabIndex = 7;
		  // 
		  // textBoxMinTick
		  // 
		  this->textBoxMinTick->Location = System::Drawing::Point(25, 200);
		  this->textBoxMinTick->Name = L"textBoxMinTick";
		  this->textBoxMinTick->Size = System::Drawing::Size(78, 22);
		  this->textBoxMinTick->TabIndex = 9;
		  // 
		  // label4
		  // 
		  this->label4->AutoSize = true;
		  this->label4->Location = System::Drawing::Point(13, 180);
		  this->label4->Name = L"label4";
		  this->label4->Size = System::Drawing::Size(109, 16);
		  this->label4->TabIndex = 8;
		  this->label4->Text = L"Минимум тиков";
		  // 
		  // textBoxMaxProc
		  // 
		  this->textBoxMaxProc->Location = System::Drawing::Point(26, 259);
		  this->textBoxMaxProc->Name = L"textBoxMaxProc";
		  this->textBoxMaxProc->Size = System::Drawing::Size(78, 22);
		  this->textBoxMaxProc->TabIndex = 11;
		  // 
		  // label5
		  // 
		  this->label5->AutoSize = true;
		  this->label5->Location = System::Drawing::Point(14, 239);
		  this->label5->Name = L"label5";
		  this->label5->Size = System::Drawing::Size(163, 16);
		  this->label5->TabIndex = 10;
		  this->label5->Text = L"Максимум процессоров";
		  // 
		  // textBoxMinProc
		  // 
		  this->textBoxMinProc->Location = System::Drawing::Point(25, 314);
		  this->textBoxMinProc->Name = L"textBoxMinProc";
		  this->textBoxMinProc->Size = System::Drawing::Size(78, 22);
		  this->textBoxMinProc->TabIndex = 13;
		  // 
		  // label6
		  // 
		  this->label6->AutoSize = true;
		  this->label6->Location = System::Drawing::Point(13, 294);
		  this->label6->Name = L"label6";
		  this->label6->Size = System::Drawing::Size(157, 16);
		  this->label6->TabIndex = 12;
		  this->label6->Text = L"Минимум процессоров";
		  // 
		  // labelCompleted
		  // 
		  this->labelCompleted->AutoSize = true;
		  this->labelCompleted->Location = System::Drawing::Point(12, 370);
		  this->labelCompleted->Name = L"labelCompleted";
		  this->labelCompleted->Size = System::Drawing::Size(149, 16);
		  this->labelCompleted->TabIndex = 14;
		  this->labelCompleted->Text = L"Выполненные задачи";
		  // 
		  // labelFree
		  // 
		  this->labelFree->AutoSize = true;
		  this->labelFree->Location = System::Drawing::Point(14, 406);
		  this->labelFree->Name = L"labelFree";
		  this->labelFree->Size = System::Drawing::Size(104, 16);
		  this->labelFree->TabIndex = 15;
		  this->labelFree->Text = L"Время простоя";
		  // 
		  // buttonStart
		  // 
		  this->buttonStart->Location = System::Drawing::Point(216, 406);
		  this->buttonStart->Name = L"buttonStart";
		  this->buttonStart->Size = System::Drawing::Size(195, 72);
		  this->buttonStart->TabIndex = 16;
		  this->buttonStart->Text = L"Старт";
		  this->buttonStart->UseVisualStyleBackColor = true;
		  this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStart_Click);
		  // 
		  // buttonStop
		  // 
		  this->buttonStop->Location = System::Drawing::Point(538, 406);
		  this->buttonStop->Name = L"buttonStop";
		  this->buttonStop->Size = System::Drawing::Size(200, 72);
		  this->buttonStop->TabIndex = 17;
		  this->buttonStop->Text = L"Стоп";
		  this->buttonStop->UseVisualStyleBackColor = true;
		  this->buttonStop->Click += gcnew System::EventHandler(this, &MyForm::buttonStop_Click);
		  // 
		  // timer1
		  // 
		  this->timer1->Interval = 2000;
		  this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
		  // 
		  // panelProc
		  // 
		  this->panelProc->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		  this->panelProc->Location = System::Drawing::Point(216, 13);
		  this->panelProc->Name = L"panelProc";
		  this->panelProc->Size = System::Drawing::Size(350, 350);
		  this->panelProc->TabIndex = 18;
		  // 
		  // MyForm
		  // 
		  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		  this->ClientSize = System::Drawing::Size(742, 490);
		  this->Controls->Add(this->panelProc);
		  this->Controls->Add(this->buttonStop);
		  this->Controls->Add(this->buttonStart);
		  this->Controls->Add(this->labelFree);
		  this->Controls->Add(this->labelCompleted);
		  this->Controls->Add(this->textBoxMinProc);
		  this->Controls->Add(this->label6);
		  this->Controls->Add(this->textBoxMaxProc);
		  this->Controls->Add(this->label5);
		  this->Controls->Add(this->textBoxMinTick);
		  this->Controls->Add(this->label4);
		  this->Controls->Add(this->textBoxMaxTick);
		  this->Controls->Add(this->label3);
		  this->Controls->Add(this->textBoxQueueSize);
		  this->Controls->Add(this->label2);
		  this->Controls->Add(this->textBoxVector);
		  this->Controls->Add(this->label1);
		  this->Controls->Add(this->panelQueue);
		  this->Name = L"MyForm";
		  this->Text = L"MyForm";
		  this->ResumeLayout(false);
		  this->PerformLayout();

		}
#pragma endregion

  private: System::Void setbuttons(int vector_size)
  {
	int colrow_count = ceil(sqrt(vector_size));
	int button_height = panelProc->Size.Height / colrow_count;
	int button_width = panelProc->Size.Width / colrow_count;

	int col = 0, row = 0;
	for (int i = 0; i < vector_size; i++)
	{
	  row = i / colrow_count;
	  col = i % colrow_count;
	  Button^ button = gcnew Button();
	  button->Enabled = false;
	  button->Text = i + " : 0";
	  button->Size = System::Drawing::Size(button_width, button_height);
	  button->Location = System::Drawing::Point(col * button_width, row * button_height);

	  panelProc->Controls->Add(button);
	}
  }
  
  private: System::Void generateTask()
  {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> tick_dis(minTickCount, maxTickCount);
	std::uniform_int_distribution<> proc_dis(minProcCount, maxProcCount);

	giveTaskCount++;
	TaskInfo task{proc_dis(gen), tick_dis(gen), giveTaskCount};
	taskQueue->push(task);
	//отображение поля с очередью
  }
  
  private: System::Void giveTask()
  {
	std::vector<int> free;
	for (int i = 0; i < proc->size(); i++)
	  if (!proc->operator[](i).isBusy) free.push_back(i);

	int tmp = 0;
	while (tmp < taskQueue->getElCount())
	{
	  TaskInfo task = taskQueue->pop();
	  if (task.procCount <= free.size())
	  {
		for (int i = 0; i < task.procCount; i++)
		{
		  proc->operator[](free[i]).taskId = task.id;
		  proc->operator[](free[i]).currentTick = 0;
		  proc->operator[](free[i]).isBusy = true;
		}

		execution->push_back(task);
		break;
	  }

	  taskQueue->push(task);
	  tmp++;
	}
  }
  
  private: System::Void procTick() 
  {
	for (int i = 0; i < proc->size(); i++)
	{
	  if (proc->operator[](i).isBusy)
	  {
		for (int j = 0; i < execution->size(); j++)
		{
		  if (proc->operator[](i).taskId == execution->operator[](j).id)
		  {
			if (proc->operator[](i).currentTick == execution->operator[](j).tickCount)
			{
			  proc->operator[](i).taskId = -1;
			  proc->operator[](i).currentTick = 0;
			  proc->operator[](i).isBusy = false;

			  auto iter = execution->cbegin();
			  execution->erase(iter + j);

			}
			else
			  proc->operator[](i).currentTick++;

			break;
		  }
		}
	  }
	  else
	  {
		proc->operator[](i).freeTime++;
	  }
	}
  }
  
  private: System::Void repaint()
  {
	for (int i = 0; i < proc->size(); i++)
	{
	  panelProc->Controls[i]->Text = i + " : " + proc->operator[](i).currentTick;
	}
	panelProc->Refresh();
  }
  
  private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) 
  {
	timer1->Stop();

	int proc_vector_size = Int32::Parse(textBoxVector->Text);
	int queue_field = Int32::Parse(textBoxVector->Text);
	int max_tick_field = Int32::Parse(textBoxVector->Text);
	int min_tick_field = Int32::Parse(textBoxVector->Text);
	int max_proc_field = Int32::Parse(textBoxVector->Text);
	int min_proc_field = Int32::Parse(textBoxVector->Text);
	if (proc_vector_size <= 0)
	  throw - 1;
	if (queue_field <= 0)
	  throw - 1;
	if (max_tick_field <= 0)
	  throw - 1;
	if (min_tick_field <= 0)
	  throw - 1;
	if (max_proc_field <= 0 || max_proc_field > proc_vector_size)
	  throw - 1;
	if (min_proc_field <= 0 || min_proc_field > proc_vector_size)
	  throw - 1;

	proc->clear();
	for (int i = 0; i < proc_vector_size; i++)
	  proc->push_back(ProcInfo{ false, -1, 0, 0 });
	execution->clear();
	
	setbuttons(proc_vector_size);

	if (taskQueue != nullptr)
	  delete taskQueue;
	taskQueue = new TQueue<TaskInfo>(queue_field);

	maxProcCount = max_proc_field;
	minProcCount = min_proc_field;
	maxTickCount = max_tick_field;
	minTickCount = min_tick_field;

	timer1->Start();
  }
  
  private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) 
  {
	timer1->Stop();
  }
  
  private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
  {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> rdis(0, 1);
	double p = rdis(gen);
	if (p < 0.5 && !taskQueue->isFull())
	  generateTask();

	giveTask();
	procTick();
	repaint();
  }
	
  };
}
