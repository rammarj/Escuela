
namespace calculadora2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Resumen de formulario
	/// </summary>
	public ref class formulario : public System::Windows::Forms::Form
	{
	public:
		formulario(void)
		{
			//todo aquí (init&config)
			this->btn_sumar = (gcnew System::Windows::Forms::Button());
			this->btn_restar = (gcnew System::Windows::Forms::Button());
			this->btn_multiplicar = (gcnew System::Windows::Forms::Button());
			this->btn_dividir = (gcnew System::Windows::Forms::Button());
			this->txt_operando_1 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_operador = (gcnew System::Windows::Forms::Label());
			this->txt_operando_2 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_resultado = (gcnew System::Windows::Forms::Label());
			this->txt_resultado = (gcnew System::Windows::Forms::TextBox());

			this->SuspendLayout();
			
			// btn_sumar configuracion
			
			this->btn_sumar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_sumar->Location = System::Drawing::Point(1, 92);
			this->btn_sumar->Name = L"btn_sumar";
			this->btn_sumar->Size = System::Drawing::Size(68, 73);
			this->btn_sumar->TabIndex = 0;
			this->btn_sumar->Text = L"+";
			this->btn_sumar->UseVisualStyleBackColor = true;
			this->btn_sumar->Click += gcnew System::EventHandler(this, &formulario::btn_sumar_Click);
			
			// btn_restar configuracion
			 
			this->btn_restar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_restar->Location = System::Drawing::Point(75, 92);
			this->btn_restar->Name = L"btn_restar";
			this->btn_restar->Size = System::Drawing::Size(75, 74);
			this->btn_restar->TabIndex = 1;
			this->btn_restar->Text = L"-";
			this->btn_restar->UseVisualStyleBackColor = true;
			this->btn_restar->Click += gcnew System::EventHandler(this, &formulario::btn_restar_Click);
			 
			// btn_multiplicar configuracion
			 
			this->btn_multiplicar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_multiplicar->Location = System::Drawing::Point(156, 92);
			this->btn_multiplicar->Name = L"btn_multiplicar";
			this->btn_multiplicar->Size = System::Drawing::Size(72, 74);
			this->btn_multiplicar->TabIndex = 2;
			this->btn_multiplicar->Text = L"*";
			this->btn_multiplicar->UseVisualStyleBackColor = true;
			this->btn_multiplicar->Click += gcnew System::EventHandler(this, &formulario::btn_multiplicar_Click);
			 
			// btn_dividir configuracion
			 
			this->btn_dividir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_dividir->Location = System::Drawing::Point(234, 93);
			this->btn_dividir->Name = L"btn_dividir";
			this->btn_dividir->Size = System::Drawing::Size(78, 73);
			this->btn_dividir->TabIndex = 3;
			this->btn_dividir->Text = L"/";
			this->btn_dividir->UseVisualStyleBackColor = true;
			this->btn_dividir->Click += gcnew System::EventHandler(this, &formulario::btn_dividir_Click);
			 
			// txt_operando_1 configuracion
			 
			this->txt_operando_1->Location = System::Drawing::Point(38, 17);
			this->txt_operando_1->Name = L"txt_operando_1";
			this->txt_operando_1->Size = System::Drawing::Size(100, 20);
			this->txt_operando_1->TabIndex = 4;
			 
			// lbl_operador configuracion
			 
			this->lbl_operador->AutoSize = true;
			this->lbl_operador->Location = System::Drawing::Point(153, 19);
			this->lbl_operador->Name = L"lbl_operador";
			this->lbl_operador->Size = System::Drawing::Size(35, 13);
			this->lbl_operador->TabIndex = 5;
			 
			// txt_operando_2 configuracion
			 
			this->txt_operando_2->Location = System::Drawing::Point(186, 16);
			this->txt_operando_2->Name = L"txt_operando_2";
			this->txt_operando_2->Size = System::Drawing::Size(100, 20);
			this->txt_operando_2->TabIndex = 6;
			 
			// lbl_resultado configuracion
			 
			this->lbl_resultado->AutoSize = true;
			this->lbl_resultado->Location = System::Drawing::Point(59, 61);
			this->lbl_resultado->Name = L"lbl_resultado";
			this->lbl_resultado->Size = System::Drawing::Size(53, 13);
			this->lbl_resultado->TabIndex = 7;
			this->lbl_resultado->Text = L"resultado:";
			// 
			// txt_resultado configuracion
			// 
			this->txt_resultado->Location = System::Drawing::Point(116, 58);
			this->txt_resultado->Name = L"txt_resultado";
			this->txt_resultado->Size = System::Drawing::Size(100, 20);
			this->txt_resultado->TabIndex = 8;
			 
			// formulario configuracion
			 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 168);

			//adds de controles de formulario
			this->Controls->Add(this->txt_resultado);
			this->Controls->Add(this->lbl_resultado);
			this->Controls->Add(this->txt_operando_2);
			this->Controls->Add(this->lbl_operador);
			this->Controls->Add(this->txt_operando_1);
			this->Controls->Add(this->btn_dividir);
			this->Controls->Add(this->btn_multiplicar);
			this->Controls->Add(this->btn_restar);
			this->Controls->Add(this->btn_sumar);
			this->Name = L"formulario";
			this->Text = L"Calculadora";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	protected:
		
		/// Limpiar los recursos del sistema.
		
		~formulario()
		{
			if (components)
			{
				delete components;
			}
		}

	//declaracion de los componentes

	private: System::Windows::Forms::Button^  btn_sumar;
	private: System::Windows::Forms::Button^  btn_restar;
	private: System::Windows::Forms::Button^  btn_multiplicar;
	private: System::Windows::Forms::Button^  btn_dividir;
	private: System::Windows::Forms::TextBox^  txt_operando_1;
	private: System::Windows::Forms::Label^  lbl_operador;
	private: System::Windows::Forms::TextBox^  txt_operando_2;
	private: System::Windows::Forms::Label^  lbl_resultado;
	private: System::Windows::Forms::TextBox^  txt_resultado;


	private:
		
		//components de la ventana(aun no se muy bien para que)

		System::ComponentModel::Container ^components;

	//click de suma
	private: System::Void btn_sumar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txt_resultado->Text = "" + hacerOperacion('+');
	}
	//operaciones
	double hacerOperacion(Char operacion){
		this->lbl_operador->Text = Char::ToString(operacion);
		try{
			double operando1 = Double::Parse(this->txt_operando_1->Text);
			double operando2 = Double::Parse(this->txt_operando_2->Text);

			double resultado = 0;
			switch (operacion){
			case '+':
				resultado = operando1 + operando2;
				break;
			case '-':
				resultado = operando1 - operando2;
				break;
			case '*':
				resultado = operando1 * operando2;
				break;
			case '/':
				if (operando2 == 0){
					MessageBox::Show(this, L"No se puede dividir por cero", L"Un error ha ocurrido!");
					return 0;
				}
				resultado = operando1 / operando2;
				break;
			default:break;
			}
			return resultado;
		}
		catch (System::FormatException^ h){
			MessageBox::Show(this, h->Message, L"Un error ha ocurrido!");
			delete h;
			//MessageBox::Show();
		}
	}
	//clic de resta
	private: System::Void btn_restar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txt_resultado->Text = "" + hacerOperacion('-');
	}
	//click de multiplicar
	private: System::Void btn_multiplicar_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txt_resultado->Text = "" + hacerOperacion('*');
	}
	//click de dividir
	private: System::Void btn_dividir_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->txt_resultado->Text = "" + hacerOperacion('/');
	}

	};
}
