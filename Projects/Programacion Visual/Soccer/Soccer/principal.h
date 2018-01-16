#include "administrar.h"
#include "jugador.h"
#include "estadisticas.h"
#include "calendar.h"

#pragma once

namespace Soccer {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de principal
	/// </summary>
	public ref class principal : public System::Windows::Forms::Form
	{
	public:
		principal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~principal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  admin_equipos;
	
	private: System::Windows::Forms::Button^  altaEquipos;
	private: System::Windows::Forms::Button^  estadisticas;
	private: System::Windows::Forms::Button^  calendario;
	private: Soccer::administrar^  frm_admin;
	private: Soccer::jugador^  frm_jugador;
	private: Soccer::estadisticas^ frm_estadisticas;
	private: Soccer::calendar^ frm_calendar;
	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(principal::typeid));
			this->admin_equipos = (gcnew System::Windows::Forms::Button());
			this->altaEquipos = (gcnew System::Windows::Forms::Button());
			this->estadisticas = (gcnew System::Windows::Forms::Button());
			this->calendario = (gcnew System::Windows::Forms::Button());

			this->frm_admin = (gcnew Soccer::administrar());
			this->frm_jugador = (gcnew Soccer::jugador());
			this->frm_estadisticas = (gcnew Soccer::estadisticas());
			this->frm_calendar = (gcnew Soccer::calendar());
			this->SuspendLayout();
			// 
			// admin_equipos
			// 
			this->admin_equipos->Location = System::Drawing::Point(34, 44);
			this->admin_equipos->Name = L"admin_equipos";
			this->admin_equipos->Size = System::Drawing::Size(103, 45);
			this->admin_equipos->TabIndex = 0;
			this->admin_equipos->Text = L"Administrar equipo";
			this->admin_equipos->UseVisualStyleBackColor = true;
			this->admin_equipos->Click += gcnew System::EventHandler(this, &principal::admin_equipos_Click);
			// 
			// altaEquipos
			// 
			this->altaEquipos->Location = System::Drawing::Point(180, 44);
			this->altaEquipos->Name = L"altaEquipos";
			this->altaEquipos->Size = System::Drawing::Size(98, 45);
			this->altaEquipos->TabIndex = 1;
			this->altaEquipos->Text = L"alta de jugadores";
			this->altaEquipos->UseVisualStyleBackColor = true;
			this->altaEquipos->Click += gcnew System::EventHandler(this, &principal::altaEquipos_Click);
			// 
			// estadisticas
			// 
			this->estadisticas->Location = System::Drawing::Point(327, 44);
			this->estadisticas->Name = L"estadisticas";
			this->estadisticas->Size = System::Drawing::Size(106, 45);
			this->estadisticas->TabIndex = 2;
			this->estadisticas->Text = L"estadisticas";
			this->estadisticas->UseVisualStyleBackColor = true;
			this->estadisticas->Click += gcnew System::EventHandler(this, &principal::estadisticas_Click);
			// 
			// calendario
			// 
			this->calendario->Location = System::Drawing::Point(180, 127);
			this->calendario->Name = L"calendario";
			this->calendario->Size = System::Drawing::Size(98, 58);
			this->calendario->TabIndex = 3;
			this->calendario->Text = L"calendario";
			this->calendario->UseVisualStyleBackColor = true;
			this->calendario->Click += gcnew System::EventHandler(this, &principal::calendario_Click);
			// 
			// principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(469, 212);
			this->Controls->Add(this->calendario);
			this->Controls->Add(this->estadisticas);
			this->Controls->Add(this->altaEquipos);
			this->Controls->Add(this->admin_equipos);
			this->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->MaximizeBox = false;
			this->Name = L"principal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"API [Administracion de equipo de futbol]";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void admin_equipos_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (this->frm_admin->IsDisposed){
					 delete this->frm_admin;
					 this->frm_admin = (gcnew Soccer::administrar());
				 }
				 //this->frm_admin->SetDisplayRectLocation();
				 this->frm_admin->ShowDialog(this);

	}
private: System::Void altaEquipos_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->frm_jugador->IsDisposed){
				 delete this->frm_jugador;
				 this->frm_jugador = (gcnew Soccer::jugador());
			 }
			 //this->frm_admin->SetDisplayRectLocation();
			 this->frm_jugador->ShowDialog(this);
}
private: System::Void estadisticas_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->frm_estadisticas->IsDisposed){
				 delete this->frm_estadisticas;
				 this->frm_estadisticas = (gcnew Soccer::estadisticas());
			 }
			 //this->frm_admin->SetDisplayRectLocation();
			 this->frm_estadisticas->ShowDialog(this);
}
private: System::Void calendario_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->frm_calendar->IsDisposed){
				 delete this->frm_calendar;
				 this->frm_calendar = (gcnew Soccer::calendar());
			 }
			 //this->frm_admin->SetDisplayRectLocation();
			 this->frm_calendar->ShowDialog(this);
}
};
}
