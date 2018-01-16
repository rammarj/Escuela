#pragma once
#include "Conexion.h"
#include "AgregarProducto.h"
#include "Nota.h"
#include "Reporte.h"
/*Lup... Enste proyecto hay backdoor + DDOS!!... encontrar and +100pts.*/
/*@author Joaquin R. Martinez [strparser_lk]*/
namespace PPx1 {

	using namespace Windows;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace WMPLib;
	/// <summary>
	/// Resumen de Inicio
	/// </summary>
	public ref class Inicio : public System::Windows::Forms::Form
	{
	public:
		Inicio()
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			inicializacionPersonalizada();
		}

	private: System::Windows::Forms::Label^  lbl_sexo;
	private: System::Windows::Forms::Label^  label2;
	private:int id_usuario, id_persona;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  cbx_filtro_usuario;
	private: System::Windows::Forms::TextBox^  txt_buscar_usuario;
	private: System::Windows::Forms::DataGridView^  dtgrd_usuarios;
	private: System::Windows::Forms::Button^  btn_agregar_usuario;
	private: System::Windows::Forms::Button^  btn_refrescar;
	private: System::Windows::Forms::Button^  btn_refrescar_provedores;
	private: System::Windows::Forms::Button^  btn_agregar_provedor;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  cbx_filtro_provedor;
	private: System::Windows::Forms::Button^  btn_buscar_provedores;
	private: System::Windows::Forms::TextBox^  txt_buscar_provedor;
	private: System::Windows::Forms::DataGridView^  dtgv_provedores;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btn_refrescar_subcategoria;
	private: System::Windows::Forms::Button^  btn_agregar_subcategoria;
	private: System::Windows::Forms::Button^  btn_buscar_subcategorias;
	private: System::Windows::Forms::TextBox^  txt_buscar_subcategorias;
	private: System::Windows::Forms::DataGridView^  dtgv_subcategorias;
	private: System::Windows::Forms::Button^  btn_refrescar_categorias;
	private: System::Windows::Forms::Button^  btn_agregar_categoria;
	private: System::Windows::Forms::Button^  btn_buscar_categoria;
	private: System::Windows::Forms::TextBox^  txt_buscar_categoria;
	private: System::Windows::Forms::DataGridView^  dtgv_categorias;
	private: System::Windows::Forms::Button^  btn_refrescar_ventas;
	private: System::Windows::Forms::Button^  btn_agregar_venta;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ComboBox^  cbx_filtro_ventas;
	private: System::Windows::Forms::Button^  btn_buscar_ventas;
	private: System::Windows::Forms::TextBox^  txt_buscar_ventas;
	private: System::Windows::Forms::DataGridView^  dtgv_ventas;
	private: System::Windows::Forms::Button^  btn_eliminar_usuario;
	private: System::Windows::Forms::Button^  btn_buscar_usuario;
	private: System::Windows::Forms::Button^  btn_eliminar_provedor;
	private: System::Windows::Forms::Button^  btn_eliminar_subcategoria;
	private: System::Windows::Forms::Button^  btn_eliminar_categoria;
	private: System::Windows::Forms::Button^  btn_eliminar_ventas;
	private: System::Windows::Forms::TabPage^  tab_realizar_venta;
	private: System::Windows::Forms::Button^  btn_terminar_compra;
	private: System::Windows::Forms::Button^  btn_eliminar_producto_comp;
	private: System::Windows::Forms::Button^  btn_agregar_producto;
	private: System::Windows::Forms::DataGridView^  dtgv_realizar_venta;
	private: System::Windows::Forms::Button^  btn_cancelar_venta;
	private: System::Windows::Forms::TabPage^  tab_productos;
	private: System::Windows::Forms::Button^  btn_eliminar_productos;
	private: System::Windows::Forms::Button^  btn_refrescar_productos;
	private: System::Windows::Forms::Button^  btn_agregar_productos;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ComboBox^  cbx_filtro_productos;
	private: System::Windows::Forms::Button^  btn_buscar_productos;
	private: System::Windows::Forms::TextBox^  txt_filtro_buscar_productos;
	private: System::Windows::Forms::DataGridView^  dtgv_productos;
	private: System::Windows::Forms::TabPage^  tab_web_browser;
	private: System::Windows::Forms::WebBrowser^  wb_misc;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  lbl_rol;
	private: System::Windows::Forms::Button^  btn_navegar_adelante;
	private: System::Windows::Forms::Button^  btn_navegar_ir;
	private: System::Windows::Forms::Button^  btn_navegar_atras;
	private: System::Windows::Forms::TextBox^  txt_navegar;
	private: System::Windows::Forms::Button^  btn_recargar;
	private: System::Windows::Forms::TabPage^  tab_miscelanea_;
	private: System::Windows::Forms::TabControl^  ctrl_tab_miscelanea;
	private: System::Windows::Forms::TabPage^  tab_media_player;
	public: AxWMPLib::AxWindowsMediaPlayer^  wmp_media_player;
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	public: System::Windows::Forms::ToolStripMenuItem^  tsmi_cerrarSesión;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmi_salir;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::Button^  btn_cargar_video;
private: System::Windows::Forms::OpenFileDialog^  fd_abrir_archivos_player;
private: System::Windows::Forms::Button^  btn_full_screen;

	private: System::Windows::Forms::Button^  btn_adelante;
	private: System::Windows::Forms::Button^  btn_play_pause;
	private: System::Windows::Forms::Button^  btn_atras;
	private: System::Windows::Forms::Button^  btn_stop;
	private: System::Windows::Forms::TrackBar^  tb_volumen;
	private: System::Windows::Forms::Label^  lbl_volumen;
	private: System::Windows::Forms::Button^  btn_mudo;
	private: System::Windows::Forms::ToolTip^  tltp_cargar;
	private: System::Windows::Forms::ListBox^  lstbx_videos;
	private: System::Windows::Forms::Button^  btn_limpiar_lista_rep;
	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  acercaDeToolStripMenuItem;


	private: System::Windows::Forms::TabPage^  tab_usuarios;
		 /// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  ctrl_tabs;
	private: System::Windows::Forms::TabPage^  tab_inicio;
	private: System::Windows::Forms::TabPage^  tab_provedores;
	private: System::Windows::Forms::TabPage^  tab_cats_subcats;
	private: System::Windows::Forms::TabPage^  tab_ventas;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  lbl_telefono;
	private: System::Windows::Forms::Label^  lbl_correo;
	private: System::Windows::Forms::Label^  lbl_nombre;
	private: System::Windows::Forms::Label^  lbl_usuario;
	private: PPx1::Conexion^ conexion;
	private: MySqlConnection^ mysql_conn;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		//helpers 
		String^ usuarios_orderby;
		String^ usuarios_filtro_busqueda;
		String^ provedores_orderby;
		String^ provedores_filtro_busqueda;
		String^ categorias_filtro_busqueda;
		String^ subcategorias_filtro_busqueda;
		String^ ventas_filtro_busqueda;
		String^ ventas_orderby;
		String^ productos_filtro_busqueda;
		String^ productos_orderby;
		int productos_agregados;
		PPx1::AgregarProducto^ frm_agregar_producto;
		bool pausa = false, mudo=false;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Inicio::typeid));
			this->ctrl_tabs = (gcnew System::Windows::Forms::TabControl());
			this->tab_inicio = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lbl_rol = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_sexo = (gcnew System::Windows::Forms::Label());
			this->lbl_telefono = (gcnew System::Windows::Forms::Label());
			this->lbl_correo = (gcnew System::Windows::Forms::Label());
			this->lbl_nombre = (gcnew System::Windows::Forms::Label());
			this->lbl_usuario = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tab_usuarios = (gcnew System::Windows::Forms::TabPage());
			this->btn_eliminar_usuario = (gcnew System::Windows::Forms::Button());
			this->btn_refrescar = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_usuario = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cbx_filtro_usuario = (gcnew System::Windows::Forms::ComboBox());
			this->btn_buscar_usuario = (gcnew System::Windows::Forms::Button());
			this->txt_buscar_usuario = (gcnew System::Windows::Forms::TextBox());
			this->dtgrd_usuarios = (gcnew System::Windows::Forms::DataGridView());
			this->tab_provedores = (gcnew System::Windows::Forms::TabPage());
			this->btn_eliminar_provedor = (gcnew System::Windows::Forms::Button());
			this->btn_refrescar_provedores = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_provedor = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cbx_filtro_provedor = (gcnew System::Windows::Forms::ComboBox());
			this->btn_buscar_provedores = (gcnew System::Windows::Forms::Button());
			this->txt_buscar_provedor = (gcnew System::Windows::Forms::TextBox());
			this->dtgv_provedores = (gcnew System::Windows::Forms::DataGridView());
			this->tab_productos = (gcnew System::Windows::Forms::TabPage());
			this->btn_eliminar_productos = (gcnew System::Windows::Forms::Button());
			this->btn_refrescar_productos = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_productos = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->cbx_filtro_productos = (gcnew System::Windows::Forms::ComboBox());
			this->btn_buscar_productos = (gcnew System::Windows::Forms::Button());
			this->txt_filtro_buscar_productos = (gcnew System::Windows::Forms::TextBox());
			this->dtgv_productos = (gcnew System::Windows::Forms::DataGridView());
			this->tab_cats_subcats = (gcnew System::Windows::Forms::TabPage());
			this->btn_eliminar_subcategoria = (gcnew System::Windows::Forms::Button());
			this->btn_eliminar_categoria = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btn_refrescar_subcategoria = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_subcategoria = (gcnew System::Windows::Forms::Button());
			this->btn_buscar_subcategorias = (gcnew System::Windows::Forms::Button());
			this->txt_buscar_subcategorias = (gcnew System::Windows::Forms::TextBox());
			this->dtgv_subcategorias = (gcnew System::Windows::Forms::DataGridView());
			this->btn_refrescar_categorias = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_categoria = (gcnew System::Windows::Forms::Button());
			this->btn_buscar_categoria = (gcnew System::Windows::Forms::Button());
			this->txt_buscar_categoria = (gcnew System::Windows::Forms::TextBox());
			this->dtgv_categorias = (gcnew System::Windows::Forms::DataGridView());
			this->tab_ventas = (gcnew System::Windows::Forms::TabPage());
			this->btn_eliminar_ventas = (gcnew System::Windows::Forms::Button());
			this->btn_refrescar_ventas = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_venta = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cbx_filtro_ventas = (gcnew System::Windows::Forms::ComboBox());
			this->btn_buscar_ventas = (gcnew System::Windows::Forms::Button());
			this->txt_buscar_ventas = (gcnew System::Windows::Forms::TextBox());
			this->dtgv_ventas = (gcnew System::Windows::Forms::DataGridView());
			this->tab_realizar_venta = (gcnew System::Windows::Forms::TabPage());
			this->btn_cancelar_venta = (gcnew System::Windows::Forms::Button());
			this->btn_terminar_compra = (gcnew System::Windows::Forms::Button());
			this->btn_eliminar_producto_comp = (gcnew System::Windows::Forms::Button());
			this->btn_agregar_producto = (gcnew System::Windows::Forms::Button());
			this->dtgv_realizar_venta = (gcnew System::Windows::Forms::DataGridView());
			this->tab_miscelanea_ = (gcnew System::Windows::Forms::TabPage());
			this->ctrl_tab_miscelanea = (gcnew System::Windows::Forms::TabControl());
			this->tab_web_browser = (gcnew System::Windows::Forms::TabPage());
			this->btn_recargar = (gcnew System::Windows::Forms::Button());
			this->btn_navegar_adelante = (gcnew System::Windows::Forms::Button());
			this->btn_navegar_ir = (gcnew System::Windows::Forms::Button());
			this->btn_navegar_atras = (gcnew System::Windows::Forms::Button());
			this->txt_navegar = (gcnew System::Windows::Forms::TextBox());
			this->wb_misc = (gcnew System::Windows::Forms::WebBrowser());
			this->tab_media_player = (gcnew System::Windows::Forms::TabPage());
			this->btn_limpiar_lista_rep = (gcnew System::Windows::Forms::Button());
			this->lstbx_videos = (gcnew System::Windows::Forms::ListBox());
			this->btn_mudo = (gcnew System::Windows::Forms::Button());
			this->lbl_volumen = (gcnew System::Windows::Forms::Label());
			this->tb_volumen = (gcnew System::Windows::Forms::TrackBar());
			this->btn_adelante = (gcnew System::Windows::Forms::Button());
			this->btn_play_pause = (gcnew System::Windows::Forms::Button());
			this->btn_atras = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->btn_full_screen = (gcnew System::Windows::Forms::Button());
			this->btn_cargar_video = (gcnew System::Windows::Forms::Button());
			this->wmp_media_player = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmi_cerrarSesión = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmi_salir = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fd_abrir_archivos_player = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tltp_cargar = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->ctrl_tabs->SuspendLayout();
			this->tab_inicio->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tab_usuarios->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrd_usuarios))->BeginInit();
			this->tab_provedores->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_provedores))->BeginInit();
			this->tab_productos->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_productos))->BeginInit();
			this->tab_cats_subcats->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_subcategorias))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_categorias))->BeginInit();
			this->tab_ventas->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_ventas))->BeginInit();
			this->tab_realizar_venta->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_realizar_venta))->BeginInit();
			this->tab_miscelanea_->SuspendLayout();
			this->ctrl_tab_miscelanea->SuspendLayout();
			this->tab_web_browser->SuspendLayout();
			this->tab_media_player->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_volumen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wmp_media_player))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ctrl_tabs
			// 
			this->ctrl_tabs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ctrl_tabs->Controls->Add(this->tab_inicio);
			this->ctrl_tabs->Controls->Add(this->tab_usuarios);
			this->ctrl_tabs->Controls->Add(this->tab_provedores);
			this->ctrl_tabs->Controls->Add(this->tab_productos);
			this->ctrl_tabs->Controls->Add(this->tab_cats_subcats);
			this->ctrl_tabs->Controls->Add(this->tab_ventas);
			this->ctrl_tabs->Controls->Add(this->tab_realizar_venta);
			this->ctrl_tabs->Controls->Add(this->tab_miscelanea_);
			this->ctrl_tabs->Location = System::Drawing::Point(0, 27);
			this->ctrl_tabs->Name = L"ctrl_tabs";
			this->ctrl_tabs->SelectedIndex = 0;
			this->ctrl_tabs->Size = System::Drawing::Size(781, 414);
			this->ctrl_tabs->TabIndex = 0;
			// 
			// tab_inicio
			// 
			this->tab_inicio->Controls->Add(this->label12);
			this->tab_inicio->Controls->Add(this->lbl_rol);
			this->tab_inicio->Controls->Add(this->label2);
			this->tab_inicio->Controls->Add(this->lbl_sexo);
			this->tab_inicio->Controls->Add(this->lbl_telefono);
			this->tab_inicio->Controls->Add(this->lbl_correo);
			this->tab_inicio->Controls->Add(this->lbl_nombre);
			this->tab_inicio->Controls->Add(this->lbl_usuario);
			this->tab_inicio->Controls->Add(this->label5);
			this->tab_inicio->Controls->Add(this->label4);
			this->tab_inicio->Controls->Add(this->label3);
			this->tab_inicio->Controls->Add(this->label1);
			this->tab_inicio->Controls->Add(this->pictureBox2);
			this->tab_inicio->Controls->Add(this->pictureBox1);
			this->tab_inicio->Location = System::Drawing::Point(4, 22);
			this->tab_inicio->Name = L"tab_inicio";
			this->tab_inicio->Padding = System::Windows::Forms::Padding(3);
			this->tab_inicio->Size = System::Drawing::Size(773, 388);
			this->tab_inicio->TabIndex = 0;
			this->tab_inicio->Text = L"Inicio";
			this->tab_inicio->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(572, 289);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(26, 13);
			this->label12->TabIndex = 14;
			this->label12->Text = L"Rol:";
			// 
			// lbl_rol
			// 
			this->lbl_rol->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_rol->AutoSize = true;
			this->lbl_rol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_rol->ForeColor = System::Drawing::Color::Maroon;
			this->lbl_rol->Location = System::Drawing::Point(604, 289);
			this->lbl_rol->Name = L"lbl_rol";
			this->lbl_rol->Size = System::Drawing::Size(39, 13);
			this->lbl_rol->TabIndex = 13;
			this->lbl_rol->Text = L"Sexo:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(564, 264);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Sexo:";
			// 
			// lbl_sexo
			// 
			this->lbl_sexo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_sexo->AutoSize = true;
			this->lbl_sexo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_sexo->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_sexo->Location = System::Drawing::Point(604, 264);
			this->lbl_sexo->Name = L"lbl_sexo";
			this->lbl_sexo->Size = System::Drawing::Size(39, 13);
			this->lbl_sexo->TabIndex = 11;
			this->lbl_sexo->Text = L"Sexo:";
			// 
			// lbl_telefono
			// 
			this->lbl_telefono->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_telefono->AutoSize = true;
			this->lbl_telefono->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_telefono->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_telefono->Location = System::Drawing::Point(378, 335);
			this->lbl_telefono->Name = L"lbl_telefono";
			this->lbl_telefono->Size = System::Drawing::Size(54, 13);
			this->lbl_telefono->TabIndex = 10;
			this->lbl_telefono->Text = L"Usuario:";
			// 
			// lbl_correo
			// 
			this->lbl_correo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_correo->AutoSize = true;
			this->lbl_correo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_correo->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_correo->Location = System::Drawing::Point(378, 313);
			this->lbl_correo->Name = L"lbl_correo";
			this->lbl_correo->Size = System::Drawing::Size(54, 13);
			this->lbl_correo->TabIndex = 9;
			this->lbl_correo->Text = L"Usuario:";
			// 
			// lbl_nombre
			// 
			this->lbl_nombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_nombre->AutoSize = true;
			this->lbl_nombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nombre->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_nombre->Location = System::Drawing::Point(378, 289);
			this->lbl_nombre->Name = L"lbl_nombre";
			this->lbl_nombre->Size = System::Drawing::Size(54, 13);
			this->lbl_nombre->TabIndex = 8;
			this->lbl_nombre->Text = L"Usuario:";
			// 
			// lbl_usuario
			// 
			this->lbl_usuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_usuario->AutoSize = true;
			this->lbl_usuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_usuario->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lbl_usuario->Location = System::Drawing::Point(378, 264);
			this->lbl_usuario->Name = L"lbl_usuario";
			this->lbl_usuario->Size = System::Drawing::Size(54, 13);
			this->lbl_usuario->TabIndex = 7;
			this->lbl_usuario->Text = L"Usuario:";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(331, 313);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Correo:";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(320, 335);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Teléfono:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(326, 264);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Usuario:";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(279, 289);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nombre completo:";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(126, 242);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(138, 131);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(34, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(704, 226);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tab_usuarios
			// 
			this->tab_usuarios->Controls->Add(this->btn_eliminar_usuario);
			this->tab_usuarios->Controls->Add(this->btn_refrescar);
			this->tab_usuarios->Controls->Add(this->btn_agregar_usuario);
			this->tab_usuarios->Controls->Add(this->label6);
			this->tab_usuarios->Controls->Add(this->cbx_filtro_usuario);
			this->tab_usuarios->Controls->Add(this->btn_buscar_usuario);
			this->tab_usuarios->Controls->Add(this->txt_buscar_usuario);
			this->tab_usuarios->Controls->Add(this->dtgrd_usuarios);
			this->tab_usuarios->Location = System::Drawing::Point(4, 22);
			this->tab_usuarios->Name = L"tab_usuarios";
			this->tab_usuarios->Padding = System::Windows::Forms::Padding(3);
			this->tab_usuarios->Size = System::Drawing::Size(773, 388);
			this->tab_usuarios->TabIndex = 1;
			this->tab_usuarios->Text = L"usuarios";
			this->tab_usuarios->UseVisualStyleBackColor = true;
			// 
			// btn_eliminar_usuario
			// 
			this->btn_eliminar_usuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_eliminar_usuario->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_usuario.Image")));
			this->btn_eliminar_usuario->Location = System::Drawing::Point(687, 106);
			this->btn_eliminar_usuario->Name = L"btn_eliminar_usuario";
			this->btn_eliminar_usuario->Size = System::Drawing::Size(75, 23);
			this->btn_eliminar_usuario->TabIndex = 8;
			this->btn_eliminar_usuario->Text = L"eliminar";
			this->btn_eliminar_usuario->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_usuario->UseVisualStyleBackColor = true;
			this->btn_eliminar_usuario->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_usuario_Click);
			// 
			// btn_refrescar
			// 
			this->btn_refrescar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_refrescar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar.Image")));
			this->btn_refrescar->Location = System::Drawing::Point(687, 135);
			this->btn_refrescar->Name = L"btn_refrescar";
			this->btn_refrescar->Size = System::Drawing::Size(75, 23);
			this->btn_refrescar->TabIndex = 7;
			this->btn_refrescar->Text = L"refrescar";
			this->btn_refrescar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_refrescar->UseVisualStyleBackColor = true;
			this->btn_refrescar->Click += gcnew System::EventHandler(this, &Inicio::btn_refrescar_Click);
			// 
			// btn_agregar_usuario
			// 
			this->btn_agregar_usuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_agregar_usuario->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_usuario.Image")));
			this->btn_agregar_usuario->Location = System::Drawing::Point(687, 80);
			this->btn_agregar_usuario->Name = L"btn_agregar_usuario";
			this->btn_agregar_usuario->Size = System::Drawing::Size(75, 23);
			this->btn_agregar_usuario->TabIndex = 6;
			this->btn_agregar_usuario->Text = L"agregar";
			this->btn_agregar_usuario->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_usuario->UseVisualStyleBackColor = true;
			this->btn_agregar_usuario->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"filtrar por:";
			// 
			// cbx_filtro_usuario
			// 
			this->cbx_filtro_usuario->FormattingEnabled = true;
			this->cbx_filtro_usuario->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"id", L"rol", L"nombre", L"apellido paterno",
					L"apellido materno", L"sexo", L"telefono", L"correo", L"entradas", L"usuario", L"fecha ultima de entrada", L"fecha de creacion"
			});
			this->cbx_filtro_usuario->Location = System::Drawing::Point(73, 30);
			this->cbx_filtro_usuario->Name = L"cbx_filtro_usuario";
			this->cbx_filtro_usuario->Size = System::Drawing::Size(121, 21);
			this->cbx_filtro_usuario->TabIndex = 4;
			this->cbx_filtro_usuario->SelectedIndexChanged += gcnew System::EventHandler(this, &Inicio::cbx_filtro_usuario_SelectedIndexChanged);
			// 
			// btn_buscar_usuario
			// 
			this->btn_buscar_usuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_buscar_usuario->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_buscar_usuario.Image")));
			this->btn_buscar_usuario->Location = System::Drawing::Point(606, 28);
			this->btn_buscar_usuario->Name = L"btn_buscar_usuario";
			this->btn_buscar_usuario->Size = System::Drawing::Size(75, 23);
			this->btn_buscar_usuario->TabIndex = 3;
			this->btn_buscar_usuario->Text = L"buscar";
			this->btn_buscar_usuario->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_buscar_usuario->UseVisualStyleBackColor = true;
			this->btn_buscar_usuario->Click += gcnew System::EventHandler(this, &Inicio::btn_buscar_usuario_Click);
			// 
			// txt_buscar_usuario
			// 
			this->txt_buscar_usuario->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_buscar_usuario->Location = System::Drawing::Point(312, 29);
			this->txt_buscar_usuario->Name = L"txt_buscar_usuario";
			this->txt_buscar_usuario->Size = System::Drawing::Size(302, 20);
			this->txt_buscar_usuario->TabIndex = 2;
			this->txt_buscar_usuario->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_buscar_usuario_KeyUp);
			// 
			// dtgrd_usuarios
			// 
			this->dtgrd_usuarios->AllowUserToAddRows = false;
			this->dtgrd_usuarios->AllowUserToDeleteRows = false;
			this->dtgrd_usuarios->AllowUserToOrderColumns = true;
			this->dtgrd_usuarios->AllowUserToResizeRows = false;
			this->dtgrd_usuarios->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dtgrd_usuarios->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgrd_usuarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgrd_usuarios->Location = System::Drawing::Point(23, 57);
			this->dtgrd_usuarios->Name = L"dtgrd_usuarios";
			this->dtgrd_usuarios->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgrd_usuarios->Size = System::Drawing::Size(658, 325);
			this->dtgrd_usuarios->TabIndex = 0;
			this->dtgrd_usuarios->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &Inicio::dtgrd_usuarios_CellBeginEdit);
			this->dtgrd_usuarios->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inicio::dtgrd_usuarios_CellValueChanged);
			// 
			// tab_provedores
			// 
			this->tab_provedores->Controls->Add(this->btn_eliminar_provedor);
			this->tab_provedores->Controls->Add(this->btn_refrescar_provedores);
			this->tab_provedores->Controls->Add(this->btn_agregar_provedor);
			this->tab_provedores->Controls->Add(this->label7);
			this->tab_provedores->Controls->Add(this->cbx_filtro_provedor);
			this->tab_provedores->Controls->Add(this->btn_buscar_provedores);
			this->tab_provedores->Controls->Add(this->txt_buscar_provedor);
			this->tab_provedores->Controls->Add(this->dtgv_provedores);
			this->tab_provedores->Location = System::Drawing::Point(4, 22);
			this->tab_provedores->Name = L"tab_provedores";
			this->tab_provedores->Size = System::Drawing::Size(773, 388);
			this->tab_provedores->TabIndex = 2;
			this->tab_provedores->Text = L"provedores";
			this->tab_provedores->UseVisualStyleBackColor = true;
			// 
			// btn_eliminar_provedor
			// 
			this->btn_eliminar_provedor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_eliminar_provedor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_provedor.Image")));
			this->btn_eliminar_provedor->Location = System::Drawing::Point(687, 102);
			this->btn_eliminar_provedor->Name = L"btn_eliminar_provedor";
			this->btn_eliminar_provedor->Size = System::Drawing::Size(75, 23);
			this->btn_eliminar_provedor->TabIndex = 15;
			this->btn_eliminar_provedor->Text = L"eliminar";
			this->btn_eliminar_provedor->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_provedor->UseVisualStyleBackColor = true;
			this->btn_eliminar_provedor->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_provedor_Click);
			// 
			// btn_refrescar_provedores
			// 
			this->btn_refrescar_provedores->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_refrescar_provedores->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar_provedores.Image")));
			this->btn_refrescar_provedores->Location = System::Drawing::Point(687, 127);
			this->btn_refrescar_provedores->Name = L"btn_refrescar_provedores";
			this->btn_refrescar_provedores->Size = System::Drawing::Size(75, 23);
			this->btn_refrescar_provedores->TabIndex = 14;
			this->btn_refrescar_provedores->Text = L"refrescar";
			this->btn_refrescar_provedores->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_refrescar_provedores->UseVisualStyleBackColor = true;
			this->btn_refrescar_provedores->Click += gcnew System::EventHandler(this, &Inicio::btn_refrescar_provedores_Click);
			// 
			// btn_agregar_provedor
			// 
			this->btn_agregar_provedor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_agregar_provedor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_provedor.Image")));
			this->btn_agregar_provedor->Location = System::Drawing::Point(687, 73);
			this->btn_agregar_provedor->Name = L"btn_agregar_provedor";
			this->btn_agregar_provedor->Size = System::Drawing::Size(75, 23);
			this->btn_agregar_provedor->TabIndex = 13;
			this->btn_agregar_provedor->Text = L"agregar";
			this->btn_agregar_provedor->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_provedor->UseVisualStyleBackColor = true;
			this->btn_agregar_provedor->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_provedor_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(20, 32);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"filtrar por:";
			// 
			// cbx_filtro_provedor
			// 
			this->cbx_filtro_provedor->FormattingEnabled = true;
			this->cbx_filtro_provedor->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"id", L"nombre", L"telefono", L"correo",
					L"direccion"
			});
			this->cbx_filtro_provedor->Location = System::Drawing::Point(73, 30);
			this->cbx_filtro_provedor->Name = L"cbx_filtro_provedor";
			this->cbx_filtro_provedor->Size = System::Drawing::Size(121, 21);
			this->cbx_filtro_provedor->TabIndex = 11;
			this->cbx_filtro_provedor->SelectedIndexChanged += gcnew System::EventHandler(this, &Inicio::cbx_filtro_provedor_SelectedIndexChanged);
			// 
			// btn_buscar_provedores
			// 
			this->btn_buscar_provedores->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_buscar_provedores->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_buscar_provedores.Image")));
			this->btn_buscar_provedores->Location = System::Drawing::Point(607, 27);
			this->btn_buscar_provedores->Name = L"btn_buscar_provedores";
			this->btn_buscar_provedores->Size = System::Drawing::Size(75, 23);
			this->btn_buscar_provedores->TabIndex = 10;
			this->btn_buscar_provedores->Text = L"buscar";
			this->btn_buscar_provedores->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_buscar_provedores->UseVisualStyleBackColor = true;
			this->btn_buscar_provedores->Click += gcnew System::EventHandler(this, &Inicio::btn_buscar_provedores_Click);
			// 
			// txt_buscar_provedor
			// 
			this->txt_buscar_provedor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_buscar_provedor->Location = System::Drawing::Point(312, 29);
			this->txt_buscar_provedor->Name = L"txt_buscar_provedor";
			this->txt_buscar_provedor->Size = System::Drawing::Size(302, 20);
			this->txt_buscar_provedor->TabIndex = 9;
			this->txt_buscar_provedor->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_buscar_provedor_KeyUp);
			// 
			// dtgv_provedores
			// 
			this->dtgv_provedores->AllowUserToAddRows = false;
			this->dtgv_provedores->AllowUserToDeleteRows = false;
			this->dtgv_provedores->AllowUserToOrderColumns = true;
			this->dtgv_provedores->AllowUserToResizeRows = false;
			this->dtgv_provedores->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dtgv_provedores->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgv_provedores->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgv_provedores->Location = System::Drawing::Point(23, 57);
			this->dtgv_provedores->Name = L"dtgv_provedores";
			this->dtgv_provedores->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgv_provedores->Size = System::Drawing::Size(658, 319);
			this->dtgv_provedores->TabIndex = 8;
			this->dtgv_provedores->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inicio::dtgv_provedores_CellValueChanged);
			// 
			// tab_productos
			// 
			this->tab_productos->Controls->Add(this->btn_eliminar_productos);
			this->tab_productos->Controls->Add(this->btn_refrescar_productos);
			this->tab_productos->Controls->Add(this->btn_agregar_productos);
			this->tab_productos->Controls->Add(this->label11);
			this->tab_productos->Controls->Add(this->cbx_filtro_productos);
			this->tab_productos->Controls->Add(this->btn_buscar_productos);
			this->tab_productos->Controls->Add(this->txt_filtro_buscar_productos);
			this->tab_productos->Controls->Add(this->dtgv_productos);
			this->tab_productos->Location = System::Drawing::Point(4, 22);
			this->tab_productos->Name = L"tab_productos";
			this->tab_productos->Size = System::Drawing::Size(773, 388);
			this->tab_productos->TabIndex = 6;
			this->tab_productos->Text = L"productos";
			this->tab_productos->UseVisualStyleBackColor = true;
			// 
			// btn_eliminar_productos
			// 
			this->btn_eliminar_productos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_eliminar_productos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_productos.Image")));
			this->btn_eliminar_productos->Location = System::Drawing::Point(689, 99);
			this->btn_eliminar_productos->Name = L"btn_eliminar_productos";
			this->btn_eliminar_productos->Size = System::Drawing::Size(75, 23);
			this->btn_eliminar_productos->TabIndex = 23;
			this->btn_eliminar_productos->Text = L"eliminar";
			this->btn_eliminar_productos->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_productos->UseVisualStyleBackColor = true;
			this->btn_eliminar_productos->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_productos_Click);
			// 
			// btn_refrescar_productos
			// 
			this->btn_refrescar_productos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_refrescar_productos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar_productos.Image")));
			this->btn_refrescar_productos->Location = System::Drawing::Point(689, 128);
			this->btn_refrescar_productos->Name = L"btn_refrescar_productos";
			this->btn_refrescar_productos->Size = System::Drawing::Size(75, 23);
			this->btn_refrescar_productos->TabIndex = 22;
			this->btn_refrescar_productos->Text = L"refrescar";
			this->btn_refrescar_productos->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_refrescar_productos->UseVisualStyleBackColor = true;
			this->btn_refrescar_productos->Click += gcnew System::EventHandler(this, &Inicio::btn_refrescar_productos_Click);
			// 
			// btn_agregar_productos
			// 
			this->btn_agregar_productos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_agregar_productos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_productos.Image")));
			this->btn_agregar_productos->Location = System::Drawing::Point(689, 70);
			this->btn_agregar_productos->Name = L"btn_agregar_productos";
			this->btn_agregar_productos->Size = System::Drawing::Size(75, 23);
			this->btn_agregar_productos->TabIndex = 21;
			this->btn_agregar_productos->Text = L"agregar";
			this->btn_agregar_productos->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_productos->UseVisualStyleBackColor = true;
			this->btn_agregar_productos->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_productos_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(16, 29);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(50, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"filtrar por:";
			// 
			// cbx_filtro_productos
			// 
			this->cbx_filtro_productos->FormattingEnabled = true;
			this->cbx_filtro_productos->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"id", L"categoria", L"subcategoria",
					L"provedor", L"nombre", L"precio", L"descripcion", L"existencia"
			});
			this->cbx_filtro_productos->Location = System::Drawing::Point(69, 27);
			this->cbx_filtro_productos->Name = L"cbx_filtro_productos";
			this->cbx_filtro_productos->Size = System::Drawing::Size(121, 21);
			this->cbx_filtro_productos->TabIndex = 19;
			this->cbx_filtro_productos->SelectedIndexChanged += gcnew System::EventHandler(this, &Inicio::cbx_filtro_productos_SelectedIndexChanged);
			// 
			// btn_buscar_productos
			// 
			this->btn_buscar_productos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_buscar_productos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_buscar_productos.Image")));
			this->btn_buscar_productos->Location = System::Drawing::Point(603, 25);
			this->btn_buscar_productos->Name = L"btn_buscar_productos";
			this->btn_buscar_productos->Size = System::Drawing::Size(75, 23);
			this->btn_buscar_productos->TabIndex = 18;
			this->btn_buscar_productos->Text = L"buscar";
			this->btn_buscar_productos->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_buscar_productos->UseVisualStyleBackColor = true;
			this->btn_buscar_productos->Click += gcnew System::EventHandler(this, &Inicio::btn_buscar_productos_Click);
			// 
			// txt_filtro_buscar_productos
			// 
			this->txt_filtro_buscar_productos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_filtro_buscar_productos->Location = System::Drawing::Point(308, 26);
			this->txt_filtro_buscar_productos->Name = L"txt_filtro_buscar_productos";
			this->txt_filtro_buscar_productos->Size = System::Drawing::Size(302, 20);
			this->txt_filtro_buscar_productos->TabIndex = 17;
			this->txt_filtro_buscar_productos->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_filtro_buscar_productos_KeyUp);
			// 
			// dtgv_productos
			// 
			this->dtgv_productos->AllowUserToAddRows = false;
			this->dtgv_productos->AllowUserToDeleteRows = false;
			this->dtgv_productos->AllowUserToOrderColumns = true;
			this->dtgv_productos->AllowUserToResizeRows = false;
			this->dtgv_productos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dtgv_productos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgv_productos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgv_productos->Location = System::Drawing::Point(19, 54);
			this->dtgv_productos->Name = L"dtgv_productos";
			this->dtgv_productos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgv_productos->Size = System::Drawing::Size(658, 321);
			this->dtgv_productos->TabIndex = 16;
			this->dtgv_productos->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &Inicio::dtgv_productos_CellBeginEdit);
			this->dtgv_productos->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inicio::dtgv_productos_CellValueChanged);
			// 
			// tab_cats_subcats
			// 
			this->tab_cats_subcats->Controls->Add(this->btn_eliminar_subcategoria);
			this->tab_cats_subcats->Controls->Add(this->btn_eliminar_categoria);
			this->tab_cats_subcats->Controls->Add(this->label10);
			this->tab_cats_subcats->Controls->Add(this->label8);
			this->tab_cats_subcats->Controls->Add(this->btn_refrescar_subcategoria);
			this->tab_cats_subcats->Controls->Add(this->btn_agregar_subcategoria);
			this->tab_cats_subcats->Controls->Add(this->btn_buscar_subcategorias);
			this->tab_cats_subcats->Controls->Add(this->txt_buscar_subcategorias);
			this->tab_cats_subcats->Controls->Add(this->dtgv_subcategorias);
			this->tab_cats_subcats->Controls->Add(this->btn_refrescar_categorias);
			this->tab_cats_subcats->Controls->Add(this->btn_agregar_categoria);
			this->tab_cats_subcats->Controls->Add(this->btn_buscar_categoria);
			this->tab_cats_subcats->Controls->Add(this->txt_buscar_categoria);
			this->tab_cats_subcats->Controls->Add(this->dtgv_categorias);
			this->tab_cats_subcats->Location = System::Drawing::Point(4, 22);
			this->tab_cats_subcats->Name = L"tab_cats_subcats";
			this->tab_cats_subcats->Size = System::Drawing::Size(773, 388);
			this->tab_cats_subcats->TabIndex = 3;
			this->tab_cats_subcats->Text = L"categorias y subcategorias";
			this->tab_cats_subcats->UseVisualStyleBackColor = true;
			// 
			// btn_eliminar_subcategoria
			// 
			this->btn_eliminar_subcategoria->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_eliminar_subcategoria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_subcategoria.Image")));
			this->btn_eliminar_subcategoria->Location = System::Drawing::Point(689, 114);
			this->btn_eliminar_subcategoria->Name = L"btn_eliminar_subcategoria";
			this->btn_eliminar_subcategoria->Size = System::Drawing::Size(75, 23);
			this->btn_eliminar_subcategoria->TabIndex = 23;
			this->btn_eliminar_subcategoria->Text = L"eliminar";
			this->btn_eliminar_subcategoria->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_subcategoria->UseVisualStyleBackColor = true;
			this->btn_eliminar_subcategoria->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_subcategoria_Click);
			// 
			// btn_eliminar_categoria
			// 
			this->btn_eliminar_categoria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_categoria.Image")));
			this->btn_eliminar_categoria->Location = System::Drawing::Point(14, 114);
			this->btn_eliminar_categoria->Name = L"btn_eliminar_categoria";
			this->btn_eliminar_categoria->Size = System::Drawing::Size(75, 23);
			this->btn_eliminar_categoria->TabIndex = 22;
			this->btn_eliminar_categoria->Text = L"eliminar";
			this->btn_eliminar_categoria->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_categoria->UseVisualStyleBackColor = true;
			this->btn_eliminar_categoria->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_categoria_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(399, 17);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(81, 13);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Subategorias";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(92, 17);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(67, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Categorias";
			// 
			// btn_refrescar_subcategoria
			// 
			this->btn_refrescar_subcategoria->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_refrescar_subcategoria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar_subcategoria.Image")));
			this->btn_refrescar_subcategoria->Location = System::Drawing::Point(689, 143);
			this->btn_refrescar_subcategoria->Name = L"btn_refrescar_subcategoria";
			this->btn_refrescar_subcategoria->Size = System::Drawing::Size(75, 23);
			this->btn_refrescar_subcategoria->TabIndex = 19;
			this->btn_refrescar_subcategoria->Text = L"refrescar";
			this->btn_refrescar_subcategoria->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_refrescar_subcategoria->UseVisualStyleBackColor = true;
			this->btn_refrescar_subcategoria->Click += gcnew System::EventHandler(this, &Inicio::btn_refrescar_subcategoria_Click);
			// 
			// btn_agregar_subcategoria
			// 
			this->btn_agregar_subcategoria->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_agregar_subcategoria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_subcategoria.Image")));
			this->btn_agregar_subcategoria->Location = System::Drawing::Point(689, 85);
			this->btn_agregar_subcategoria->Name = L"btn_agregar_subcategoria";
			this->btn_agregar_subcategoria->Size = System::Drawing::Size(75, 23);
			this->btn_agregar_subcategoria->TabIndex = 18;
			this->btn_agregar_subcategoria->Text = L"agregar";
			this->btn_agregar_subcategoria->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_subcategoria->UseVisualStyleBackColor = true;
			this->btn_agregar_subcategoria->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_subcategoria_Click);
			// 
			// btn_buscar_subcategorias
			// 
			this->btn_buscar_subcategorias->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_buscar_subcategorias->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_buscar_subcategorias.Image")));
			this->btn_buscar_subcategorias->Location = System::Drawing::Point(608, 42);
			this->btn_buscar_subcategorias->Name = L"btn_buscar_subcategorias";
			this->btn_buscar_subcategorias->Size = System::Drawing::Size(75, 23);
			this->btn_buscar_subcategorias->TabIndex = 17;
			this->btn_buscar_subcategorias->Text = L"buscar";
			this->btn_buscar_subcategorias->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_buscar_subcategorias->UseVisualStyleBackColor = true;
			this->btn_buscar_subcategorias->Click += gcnew System::EventHandler(this, &Inicio::btn_buscar_subcategorias_Click);
			// 
			// txt_buscar_subcategorias
			// 
			this->txt_buscar_subcategorias->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_buscar_subcategorias->Location = System::Drawing::Point(374, 44);
			this->txt_buscar_subcategorias->Name = L"txt_buscar_subcategorias";
			this->txt_buscar_subcategorias->Size = System::Drawing::Size(238, 20);
			this->txt_buscar_subcategorias->TabIndex = 16;
			this->txt_buscar_subcategorias->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_buscar_subcategorias_KeyUp);
			// 
			// dtgv_subcategorias
			// 
			this->dtgv_subcategorias->AllowUserToAddRows = false;
			this->dtgv_subcategorias->AllowUserToDeleteRows = false;
			this->dtgv_subcategorias->AllowUserToOrderColumns = true;
			this->dtgv_subcategorias->AllowUserToResizeRows = false;
			this->dtgv_subcategorias->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dtgv_subcategorias->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgv_subcategorias->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgv_subcategorias->Location = System::Drawing::Point(374, 85);
			this->dtgv_subcategorias->Name = L"dtgv_subcategorias";
			this->dtgv_subcategorias->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dtgv_subcategorias->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgv_subcategorias->Size = System::Drawing::Size(309, 285);
			this->dtgv_subcategorias->TabIndex = 15;
			this->dtgv_subcategorias->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &Inicio::dtgv_subcategorias_CellBeginEdit);
			this->dtgv_subcategorias->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inicio::dtgv_subcategorias_CellValueChanged);
			// 
			// btn_refrescar_categorias
			// 
			this->btn_refrescar_categorias->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar_categorias.Image")));
			this->btn_refrescar_categorias->Location = System::Drawing::Point(14, 143);
			this->btn_refrescar_categorias->Name = L"btn_refrescar_categorias";
			this->btn_refrescar_categorias->Size = System::Drawing::Size(75, 23);
			this->btn_refrescar_categorias->TabIndex = 14;
			this->btn_refrescar_categorias->Text = L"refrescar";
			this->btn_refrescar_categorias->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_refrescar_categorias->UseVisualStyleBackColor = true;
			this->btn_refrescar_categorias->Click += gcnew System::EventHandler(this, &Inicio::btn_refrescar_categorias_Click);
			// 
			// btn_agregar_categoria
			// 
			this->btn_agregar_categoria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_categoria.Image")));
			this->btn_agregar_categoria->Location = System::Drawing::Point(14, 85);
			this->btn_agregar_categoria->Name = L"btn_agregar_categoria";
			this->btn_agregar_categoria->Size = System::Drawing::Size(75, 23);
			this->btn_agregar_categoria->TabIndex = 13;
			this->btn_agregar_categoria->Text = L"agregar";
			this->btn_agregar_categoria->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_categoria->UseVisualStyleBackColor = true;
			this->btn_agregar_categoria->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_categoria_Click);
			// 
			// btn_buscar_categoria
			// 
			this->btn_buscar_categoria->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_buscar_categoria.Image")));
			this->btn_buscar_categoria->Location = System::Drawing::Point(271, 42);
			this->btn_buscar_categoria->Name = L"btn_buscar_categoria";
			this->btn_buscar_categoria->Size = System::Drawing::Size(75, 23);
			this->btn_buscar_categoria->TabIndex = 10;
			this->btn_buscar_categoria->Text = L"buscar";
			this->btn_buscar_categoria->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_buscar_categoria->UseVisualStyleBackColor = true;
			this->btn_buscar_categoria->Click += gcnew System::EventHandler(this, &Inicio::btn_buscar_categoria_Click);
			// 
			// txt_buscar_categoria
			// 
			this->txt_buscar_categoria->Location = System::Drawing::Point(95, 44);
			this->txt_buscar_categoria->Name = L"txt_buscar_categoria";
			this->txt_buscar_categoria->Size = System::Drawing::Size(179, 20);
			this->txt_buscar_categoria->TabIndex = 9;
			this->txt_buscar_categoria->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_buscar_categoria_KeyUp);
			// 
			// dtgv_categorias
			// 
			this->dtgv_categorias->AllowUserToAddRows = false;
			this->dtgv_categorias->AllowUserToDeleteRows = false;
			this->dtgv_categorias->AllowUserToOrderColumns = true;
			this->dtgv_categorias->AllowUserToResizeRows = false;
			this->dtgv_categorias->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dtgv_categorias->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgv_categorias->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgv_categorias->Location = System::Drawing::Point(95, 85);
			this->dtgv_categorias->Name = L"dtgv_categorias";
			this->dtgv_categorias->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgv_categorias->Size = System::Drawing::Size(251, 285);
			this->dtgv_categorias->TabIndex = 8;
			this->dtgv_categorias->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inicio::dtgv_categorias_CellValueChanged);
			// 
			// tab_ventas
			// 
			this->tab_ventas->Controls->Add(this->btn_eliminar_ventas);
			this->tab_ventas->Controls->Add(this->btn_refrescar_ventas);
			this->tab_ventas->Controls->Add(this->btn_agregar_venta);
			this->tab_ventas->Controls->Add(this->label9);
			this->tab_ventas->Controls->Add(this->cbx_filtro_ventas);
			this->tab_ventas->Controls->Add(this->btn_buscar_ventas);
			this->tab_ventas->Controls->Add(this->txt_buscar_ventas);
			this->tab_ventas->Controls->Add(this->dtgv_ventas);
			this->tab_ventas->Location = System::Drawing::Point(4, 22);
			this->tab_ventas->Name = L"tab_ventas";
			this->tab_ventas->Size = System::Drawing::Size(773, 388);
			this->tab_ventas->TabIndex = 4;
			this->tab_ventas->Text = L"ventas";
			this->tab_ventas->UseVisualStyleBackColor = true;
			// 
			// btn_eliminar_ventas
			// 
			this->btn_eliminar_ventas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_eliminar_ventas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_ventas.Image")));
			this->btn_eliminar_ventas->Location = System::Drawing::Point(693, 102);
			this->btn_eliminar_ventas->Name = L"btn_eliminar_ventas";
			this->btn_eliminar_ventas->Size = System::Drawing::Size(75, 23);
			this->btn_eliminar_ventas->TabIndex = 15;
			this->btn_eliminar_ventas->Text = L"eliminar";
			this->btn_eliminar_ventas->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_ventas->UseVisualStyleBackColor = true;
			this->btn_eliminar_ventas->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_ventas_Click);
			// 
			// btn_refrescar_ventas
			// 
			this->btn_refrescar_ventas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_refrescar_ventas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_refrescar_ventas.Image")));
			this->btn_refrescar_ventas->Location = System::Drawing::Point(693, 131);
			this->btn_refrescar_ventas->Name = L"btn_refrescar_ventas";
			this->btn_refrescar_ventas->Size = System::Drawing::Size(75, 23);
			this->btn_refrescar_ventas->TabIndex = 14;
			this->btn_refrescar_ventas->Text = L"refrescar";
			this->btn_refrescar_ventas->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_refrescar_ventas->UseVisualStyleBackColor = true;
			this->btn_refrescar_ventas->Click += gcnew System::EventHandler(this, &Inicio::btn_refrescar_ventas_Click);
			// 
			// btn_agregar_venta
			// 
			this->btn_agregar_venta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_agregar_venta->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_venta.Image")));
			this->btn_agregar_venta->Location = System::Drawing::Point(693, 73);
			this->btn_agregar_venta->Name = L"btn_agregar_venta";
			this->btn_agregar_venta->Size = System::Drawing::Size(75, 23);
			this->btn_agregar_venta->TabIndex = 13;
			this->btn_agregar_venta->Text = L"agregar";
			this->btn_agregar_venta->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_venta->UseVisualStyleBackColor = true;
			this->btn_agregar_venta->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_venta_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(20, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"filtrar por:";
			// 
			// cbx_filtro_ventas
			// 
			this->cbx_filtro_ventas->FormattingEnabled = true;
			this->cbx_filtro_ventas->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"id", L"fecha", L"nota" });
			this->cbx_filtro_ventas->Location = System::Drawing::Point(73, 30);
			this->cbx_filtro_ventas->Name = L"cbx_filtro_ventas";
			this->cbx_filtro_ventas->Size = System::Drawing::Size(121, 21);
			this->cbx_filtro_ventas->TabIndex = 11;
			this->cbx_filtro_ventas->SelectedIndexChanged += gcnew System::EventHandler(this, &Inicio::cbx_filtro_ventas_SelectedIndexChanged);
			// 
			// btn_buscar_ventas
			// 
			this->btn_buscar_ventas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_buscar_ventas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_buscar_ventas.Image")));
			this->btn_buscar_ventas->Location = System::Drawing::Point(607, 27);
			this->btn_buscar_ventas->Name = L"btn_buscar_ventas";
			this->btn_buscar_ventas->Size = System::Drawing::Size(75, 23);
			this->btn_buscar_ventas->TabIndex = 10;
			this->btn_buscar_ventas->Text = L"buscar";
			this->btn_buscar_ventas->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_buscar_ventas->UseVisualStyleBackColor = true;
			this->btn_buscar_ventas->Click += gcnew System::EventHandler(this, &Inicio::btn_buscar_ventas_Click);
			// 
			// txt_buscar_ventas
			// 
			this->txt_buscar_ventas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_buscar_ventas->Location = System::Drawing::Point(312, 29);
			this->txt_buscar_ventas->Name = L"txt_buscar_ventas";
			this->txt_buscar_ventas->Size = System::Drawing::Size(302, 20);
			this->txt_buscar_ventas->TabIndex = 9;
			this->txt_buscar_ventas->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_buscar_ventas_KeyUp);
			// 
			// dtgv_ventas
			// 
			this->dtgv_ventas->AllowUserToAddRows = false;
			this->dtgv_ventas->AllowUserToDeleteRows = false;
			this->dtgv_ventas->AllowUserToOrderColumns = true;
			this->dtgv_ventas->AllowUserToResizeRows = false;
			this->dtgv_ventas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dtgv_ventas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgv_ventas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgv_ventas->Location = System::Drawing::Point(23, 57);
			this->dtgv_ventas->Name = L"dtgv_ventas";
			this->dtgv_ventas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgv_ventas->Size = System::Drawing::Size(659, 316);
			this->dtgv_ventas->TabIndex = 8;
			this->dtgv_ventas->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inicio::dtgv_ventas_CellValueChanged);
			// 
			// tab_realizar_venta
			// 
			this->tab_realizar_venta->Controls->Add(this->btn_cancelar_venta);
			this->tab_realizar_venta->Controls->Add(this->btn_terminar_compra);
			this->tab_realizar_venta->Controls->Add(this->btn_eliminar_producto_comp);
			this->tab_realizar_venta->Controls->Add(this->btn_agregar_producto);
			this->tab_realizar_venta->Controls->Add(this->dtgv_realizar_venta);
			this->tab_realizar_venta->Location = System::Drawing::Point(4, 22);
			this->tab_realizar_venta->Name = L"tab_realizar_venta";
			this->tab_realizar_venta->Size = System::Drawing::Size(773, 388);
			this->tab_realizar_venta->TabIndex = 5;
			this->tab_realizar_venta->Text = L"realizar venta";
			this->tab_realizar_venta->UseVisualStyleBackColor = true;
			// 
			// btn_cancelar_venta
			// 
			this->btn_cancelar_venta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_cancelar_venta->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_cancelar_venta.Image")));
			this->btn_cancelar_venta->Location = System::Drawing::Point(656, 92);
			this->btn_cancelar_venta->Name = L"btn_cancelar_venta";
			this->btn_cancelar_venta->Size = System::Drawing::Size(100, 23);
			this->btn_cancelar_venta->TabIndex = 4;
			this->btn_cancelar_venta->Text = L"cancelar";
			this->btn_cancelar_venta->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_cancelar_venta->UseVisualStyleBackColor = true;
			this->btn_cancelar_venta->Click += gcnew System::EventHandler(this, &Inicio::btn_cancelar_venta_Click);
			// 
			// btn_terminar_compra
			// 
			this->btn_terminar_compra->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_terminar_compra->BackColor = System::Drawing::Color::Gainsboro;
			this->btn_terminar_compra->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_terminar_compra.Image")));
			this->btn_terminar_compra->Location = System::Drawing::Point(656, 121);
			this->btn_terminar_compra->Name = L"btn_terminar_compra";
			this->btn_terminar_compra->Size = System::Drawing::Size(100, 37);
			this->btn_terminar_compra->TabIndex = 3;
			this->btn_terminar_compra->Text = L"terminar la compra";
			this->btn_terminar_compra->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_terminar_compra->UseVisualStyleBackColor = false;
			this->btn_terminar_compra->Click += gcnew System::EventHandler(this, &Inicio::btn_terminar_compra_Click);
			// 
			// btn_eliminar_producto_comp
			// 
			this->btn_eliminar_producto_comp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_eliminar_producto_comp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_eliminar_producto_comp.Image")));
			this->btn_eliminar_producto_comp->Location = System::Drawing::Point(656, 63);
			this->btn_eliminar_producto_comp->Name = L"btn_eliminar_producto_comp";
			this->btn_eliminar_producto_comp->Size = System::Drawing::Size(100, 23);
			this->btn_eliminar_producto_comp->TabIndex = 2;
			this->btn_eliminar_producto_comp->Text = L"eliminar";
			this->btn_eliminar_producto_comp->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_eliminar_producto_comp->UseVisualStyleBackColor = true;
			this->btn_eliminar_producto_comp->Click += gcnew System::EventHandler(this, &Inicio::btn_eliminar_producto_comp_Click);
			// 
			// btn_agregar_producto
			// 
			this->btn_agregar_producto->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_agregar_producto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_agregar_producto.Image")));
			this->btn_agregar_producto->Location = System::Drawing::Point(656, 17);
			this->btn_agregar_producto->Name = L"btn_agregar_producto";
			this->btn_agregar_producto->Size = System::Drawing::Size(100, 40);
			this->btn_agregar_producto->TabIndex = 1;
			this->btn_agregar_producto->Text = L"agregar producto";
			this->btn_agregar_producto->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_agregar_producto->UseVisualStyleBackColor = true;
			this->btn_agregar_producto->Click += gcnew System::EventHandler(this, &Inicio::btn_agregar_producto_Click);
			// 
			// dtgv_realizar_venta
			// 
			this->dtgv_realizar_venta->AllowUserToAddRows = false;
			this->dtgv_realizar_venta->AllowUserToDeleteRows = false;
			this->dtgv_realizar_venta->AllowUserToResizeRows = false;
			this->dtgv_realizar_venta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dtgv_realizar_venta->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dtgv_realizar_venta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtgv_realizar_venta->Location = System::Drawing::Point(26, 20);
			this->dtgv_realizar_venta->Name = L"dtgv_realizar_venta";
			this->dtgv_realizar_venta->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dtgv_realizar_venta->Size = System::Drawing::Size(624, 347);
			this->dtgv_realizar_venta->TabIndex = 0;
			// 
			// tab_miscelanea_
			// 
			this->tab_miscelanea_->Controls->Add(this->ctrl_tab_miscelanea);
			this->tab_miscelanea_->Location = System::Drawing::Point(4, 22);
			this->tab_miscelanea_->Name = L"tab_miscelanea_";
			this->tab_miscelanea_->Size = System::Drawing::Size(773, 388);
			this->tab_miscelanea_->TabIndex = 8;
			this->tab_miscelanea_->Text = L"miscelanea";
			this->tab_miscelanea_->UseVisualStyleBackColor = true;
			// 
			// ctrl_tab_miscelanea
			// 
			this->ctrl_tab_miscelanea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ctrl_tab_miscelanea->Controls->Add(this->tab_web_browser);
			this->ctrl_tab_miscelanea->Controls->Add(this->tab_media_player);
			this->ctrl_tab_miscelanea->Location = System::Drawing::Point(0, 0);
			this->ctrl_tab_miscelanea->Name = L"ctrl_tab_miscelanea";
			this->ctrl_tab_miscelanea->SelectedIndex = 0;
			this->ctrl_tab_miscelanea->Size = System::Drawing::Size(777, 388);
			this->ctrl_tab_miscelanea->TabIndex = 0;
			// 
			// tab_web_browser
			// 
			this->tab_web_browser->Controls->Add(this->btn_recargar);
			this->tab_web_browser->Controls->Add(this->btn_navegar_adelante);
			this->tab_web_browser->Controls->Add(this->btn_navegar_ir);
			this->tab_web_browser->Controls->Add(this->btn_navegar_atras);
			this->tab_web_browser->Controls->Add(this->txt_navegar);
			this->tab_web_browser->Controls->Add(this->wb_misc);
			this->tab_web_browser->Location = System::Drawing::Point(4, 22);
			this->tab_web_browser->Name = L"tab_web_browser";
			this->tab_web_browser->Size = System::Drawing::Size(769, 362);
			this->tab_web_browser->TabIndex = 7;
			this->tab_web_browser->Text = L"explorador de internet";
			this->tab_web_browser->UseVisualStyleBackColor = true;
			// 
			// btn_recargar
			// 
			this->btn_recargar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_recargar.Image")));
			this->btn_recargar->Location = System::Drawing::Point(78, 5);
			this->btn_recargar->Name = L"btn_recargar";
			this->btn_recargar->Size = System::Drawing::Size(30, 25);
			this->btn_recargar->TabIndex = 5;
			this->tltp_cargar->SetToolTip(this->btn_recargar, L"refrescar");
			this->btn_recargar->UseVisualStyleBackColor = true;
			this->btn_recargar->Click += gcnew System::EventHandler(this, &Inicio::btn_recargar_Click);
			// 
			// btn_navegar_adelante
			// 
			this->btn_navegar_adelante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_navegar_adelante.Image")));
			this->btn_navegar_adelante->Location = System::Drawing::Point(51, 5);
			this->btn_navegar_adelante->Name = L"btn_navegar_adelante";
			this->btn_navegar_adelante->Size = System::Drawing::Size(29, 24);
			this->btn_navegar_adelante->TabIndex = 4;
			this->tltp_cargar->SetToolTip(this->btn_navegar_adelante, L"adelante");
			this->btn_navegar_adelante->UseVisualStyleBackColor = true;
			this->btn_navegar_adelante->Click += gcnew System::EventHandler(this, &Inicio::btn_navegar_adelante_Click);
			// 
			// btn_navegar_ir
			// 
			this->btn_navegar_ir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_navegar_ir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_navegar_ir.Image")));
			this->btn_navegar_ir->Location = System::Drawing::Point(732, 5);
			this->btn_navegar_ir->Name = L"btn_navegar_ir";
			this->btn_navegar_ir->Size = System::Drawing::Size(31, 23);
			this->btn_navegar_ir->TabIndex = 3;
			this->tltp_cargar->SetToolTip(this->btn_navegar_ir, L"ir");
			this->btn_navegar_ir->UseVisualStyleBackColor = true;
			this->btn_navegar_ir->Click += gcnew System::EventHandler(this, &Inicio::btn_navegar_ir_Click);
			// 
			// btn_navegar_atras
			// 
			this->btn_navegar_atras->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_navegar_atras.Image")));
			this->btn_navegar_atras->Location = System::Drawing::Point(23, 5);
			this->btn_navegar_atras->Name = L"btn_navegar_atras";
			this->btn_navegar_atras->Size = System::Drawing::Size(30, 24);
			this->btn_navegar_atras->TabIndex = 2;
			this->tltp_cargar->SetToolTip(this->btn_navegar_atras, L"atras");
			this->btn_navegar_atras->UseVisualStyleBackColor = true;
			this->btn_navegar_atras->Click += gcnew System::EventHandler(this, &Inicio::btn_navegar_atras_Click);
			// 
			// txt_navegar
			// 
			this->txt_navegar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txt_navegar->Location = System::Drawing::Point(114, 7);
			this->txt_navegar->Name = L"txt_navegar";
			this->txt_navegar->Size = System::Drawing::Size(613, 20);
			this->txt_navegar->TabIndex = 1;
			this->txt_navegar->Text = L"https://github.com/JoaquinRMtz/";
			this->tltp_cargar->SetToolTip(this->txt_navegar, L"uri del documento");
			this->txt_navegar->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::txt_navegar_KeyUp);
			// 
			// wb_misc
			// 
			this->wb_misc->AllowWebBrowserDrop = false;
			this->wb_misc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->wb_misc->Location = System::Drawing::Point(8, 31);
			this->wb_misc->MinimumSize = System::Drawing::Size(20, 20);
			this->wb_misc->Name = L"wb_misc";
			this->wb_misc->Size = System::Drawing::Size(760, 354);
			this->wb_misc->TabIndex = 0;
			this->wb_misc->Url = (gcnew System::Uri(L"https://github.com/JoaquinRMtz/", System::UriKind::Absolute));
			this->wb_misc->Navigated += gcnew System::Windows::Forms::WebBrowserNavigatedEventHandler(this, &Inicio::wb_misc_Navigated);
			// 
			// tab_media_player
			// 
			this->tab_media_player->Controls->Add(this->btn_limpiar_lista_rep);
			this->tab_media_player->Controls->Add(this->lstbx_videos);
			this->tab_media_player->Controls->Add(this->btn_mudo);
			this->tab_media_player->Controls->Add(this->lbl_volumen);
			this->tab_media_player->Controls->Add(this->tb_volumen);
			this->tab_media_player->Controls->Add(this->btn_adelante);
			this->tab_media_player->Controls->Add(this->btn_play_pause);
			this->tab_media_player->Controls->Add(this->btn_atras);
			this->tab_media_player->Controls->Add(this->btn_stop);
			this->tab_media_player->Controls->Add(this->btn_full_screen);
			this->tab_media_player->Controls->Add(this->btn_cargar_video);
			this->tab_media_player->Controls->Add(this->wmp_media_player);
			this->tab_media_player->Location = System::Drawing::Point(4, 22);
			this->tab_media_player->Name = L"tab_media_player";
			this->tab_media_player->Size = System::Drawing::Size(769, 362);
			this->tab_media_player->TabIndex = 8;
			this->tab_media_player->Text = L"media player";
			this->tab_media_player->UseVisualStyleBackColor = true;
			// 
			// btn_limpiar_lista_rep
			// 
			this->btn_limpiar_lista_rep->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_limpiar_lista_rep->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_limpiar_lista_rep.Image")));
			this->btn_limpiar_lista_rep->Location = System::Drawing::Point(606, 335);
			this->btn_limpiar_lista_rep->Name = L"btn_limpiar_lista_rep";
			this->btn_limpiar_lista_rep->Size = System::Drawing::Size(160, 23);
			this->btn_limpiar_lista_rep->TabIndex = 12;
			this->btn_limpiar_lista_rep->Text = L"limpiar lista de reproduccion";
			this->btn_limpiar_lista_rep->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btn_limpiar_lista_rep->UseVisualStyleBackColor = true;
			this->btn_limpiar_lista_rep->Click += gcnew System::EventHandler(this, &Inicio::btn_limpiar_lista_rep_Click);
			// 
			// lstbx_videos
			// 
			this->lstbx_videos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lstbx_videos->FormattingEnabled = true;
			this->lstbx_videos->Location = System::Drawing::Point(606, 0);
			this->lstbx_videos->Name = L"lstbx_videos";
			this->lstbx_videos->Size = System::Drawing::Size(158, 329);
			this->lstbx_videos->TabIndex = 11;
			this->lstbx_videos->Click += gcnew System::EventHandler(this, &Inicio::lstbx_videos_Click);
			// 
			// btn_mudo
			// 
			this->btn_mudo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_mudo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_mudo.Image")));
			this->btn_mudo->Location = System::Drawing::Point(79, 336);
			this->btn_mudo->Name = L"btn_mudo";
			this->btn_mudo->Size = System::Drawing::Size(32, 23);
			this->btn_mudo->TabIndex = 10;
			this->tltp_cargar->SetToolTip(this->btn_mudo, L"sonido/mudo");
			this->btn_mudo->UseVisualStyleBackColor = true;
			this->btn_mudo->Click += gcnew System::EventHandler(this, &Inicio::btn_mudo_Click);
			// 
			// lbl_volumen
			// 
			this->lbl_volumen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lbl_volumen->AutoSize = true;
			this->lbl_volumen->Location = System::Drawing::Point(5, 337);
			this->lbl_volumen->Name = L"lbl_volumen";
			this->lbl_volumen->Size = System::Drawing::Size(41, 13);
			this->lbl_volumen->TabIndex = 9;
			this->lbl_volumen->Text = L"label13";
			// 
			// tb_volumen
			// 
			this->tb_volumen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->tb_volumen->Cursor = System::Windows::Forms::Cursors::Hand;
			this->tb_volumen->Location = System::Drawing::Point(106, 336);
			this->tb_volumen->Maximum = 100;
			this->tb_volumen->Name = L"tb_volumen";
			this->tb_volumen->Size = System::Drawing::Size(200, 45);
			this->tb_volumen->TabIndex = 8;
			this->tb_volumen->TickStyle = System::Windows::Forms::TickStyle::None;
			this->tltp_cargar->SetToolTip(this->tb_volumen, L"volumen");
			this->tb_volumen->Scroll += gcnew System::EventHandler(this, &Inicio::tb_volumen_Scroll);
			// 
			// btn_adelante
			// 
			this->btn_adelante->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_adelante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_adelante.Image")));
			this->btn_adelante->Location = System::Drawing::Point(364, 337);
			this->btn_adelante->Name = L"btn_adelante";
			this->btn_adelante->Size = System::Drawing::Size(27, 23);
			this->btn_adelante->TabIndex = 7;
			this->tltp_cargar->SetToolTip(this->btn_adelante, L"siguiente");
			this->btn_adelante->UseVisualStyleBackColor = true;
			this->btn_adelante->Click += gcnew System::EventHandler(this, &Inicio::btn_adelante_Click);
			// 
			// btn_play_pause
			// 
			this->btn_play_pause->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_play_pause->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_play_pause.Image")));
			this->btn_play_pause->Location = System::Drawing::Point(336, 337);
			this->btn_play_pause->Name = L"btn_play_pause";
			this->btn_play_pause->Size = System::Drawing::Size(29, 23);
			this->btn_play_pause->TabIndex = 6;
			this->tltp_cargar->SetToolTip(this->btn_play_pause, L"play/pausa");
			this->btn_play_pause->UseVisualStyleBackColor = false;
			this->btn_play_pause->Click += gcnew System::EventHandler(this, &Inicio::btn_play_pause_Click);
			// 
			// btn_atras
			// 
			this->btn_atras->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_atras->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_atras.Image")));
			this->btn_atras->Location = System::Drawing::Point(312, 337);
			this->btn_atras->Name = L"btn_atras";
			this->btn_atras->Size = System::Drawing::Size(28, 23);
			this->btn_atras->TabIndex = 5;
			this->tltp_cargar->SetToolTip(this->btn_atras, L"anterior");
			this->btn_atras->UseVisualStyleBackColor = true;
			this->btn_atras->Click += gcnew System::EventHandler(this, &Inicio::btn_atras_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_stop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_stop.Image")));
			this->btn_stop->Location = System::Drawing::Point(390, 337);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(26, 23);
			this->btn_stop->TabIndex = 3;
			this->tltp_cargar->SetToolTip(this->btn_stop, L"parar");
			this->btn_stop->UseVisualStyleBackColor = true;
			this->btn_stop->Click += gcnew System::EventHandler(this, &Inicio::btn_stop_Click);
			// 
			// btn_full_screen
			// 
			this->btn_full_screen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_full_screen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_full_screen.Image")));
			this->btn_full_screen->Location = System::Drawing::Point(415, 337);
			this->btn_full_screen->Name = L"btn_full_screen";
			this->btn_full_screen->Size = System::Drawing::Size(27, 23);
			this->btn_full_screen->TabIndex = 2;
			this->tltp_cargar->SetToolTip(this->btn_full_screen, L"full screen");
			this->btn_full_screen->UseVisualStyleBackColor = true;
			this->btn_full_screen->Click += gcnew System::EventHandler(this, &Inicio::btn_full_screen_Click);
			// 
			// btn_cargar_video
			// 
			this->btn_cargar_video->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_cargar_video->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_cargar_video.Image")));
			this->btn_cargar_video->Location = System::Drawing::Point(441, 337);
			this->btn_cargar_video->Name = L"btn_cargar_video";
			this->btn_cargar_video->Size = System::Drawing::Size(46, 23);
			this->btn_cargar_video->TabIndex = 1;
			this->btn_cargar_video->Text = L" ...";
			this->btn_cargar_video->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->tltp_cargar->SetToolTip(this->btn_cargar_video, L"cargar archivos");
			this->btn_cargar_video->UseVisualStyleBackColor = true;
			this->btn_cargar_video->Click += gcnew System::EventHandler(this, &Inicio::btn_cargar_video_Click);
			// 
			// wmp_media_player
			// 
			this->wmp_media_player->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->wmp_media_player->Enabled = true;
			this->wmp_media_player->Location = System::Drawing::Point(0, 0);
			this->wmp_media_player->Name = L"wmp_media_player";
			this->wmp_media_player->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"wmp_media_player.OcxState")));
			this->wmp_media_player->Size = System::Drawing::Size(600, 330);
			this->wmp_media_player->TabIndex = 0;
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tsmi_cerrarSesión,
					this->tsmi_salir
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->archivoToolStripMenuItem->Text = L"Principal";
			// 
			// tsmi_cerrarSesión
			// 
			this->tsmi_cerrarSesión->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsmi_cerrarSesión.Image")));
			this->tsmi_cerrarSesión->Name = L"tsmi_cerrarSesión";
			this->tsmi_cerrarSesión->Size = System::Drawing::Size(142, 22);
			this->tsmi_cerrarSesión->Text = L"Cerrar sesión";
			// 
			// tsmi_salir
			// 
			this->tsmi_salir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsmi_salir.Image")));
			this->tsmi_salir->Name = L"tsmi_salir";
			this->tsmi_salir->Size = System::Drawing::Size(142, 22);
			this->tsmi_salir->Text = L"salir";
			this->tsmi_salir->Click += gcnew System::EventHandler(this, &Inicio::salirToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->archivoToolStripMenuItem,
					this->ayudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->acercaDeToolStripMenuItem });
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"acercaDeToolStripMenuItem.Image")));
			this->acercaDeToolStripMenuItem->Name = L"acercaDeToolStripMenuItem";
			this->acercaDeToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->acercaDeToolStripMenuItem->Text = L"acerca de...";
			this->acercaDeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Inicio::acercaDeToolStripMenuItem_Click);
			// 
			// fd_abrir_archivos_player
			// 
			this->fd_abrir_archivos_player->Filter = L"|*.mp4|*.avi|*.wmv";
			this->fd_abrir_archivos_player->Multiselect = true;
			// 
			// tltp_cargar
			// 
			this->tltp_cargar->BackColor = System::Drawing::SystemColors::ControlDark;
			this->tltp_cargar->ForeColor = System::Drawing::SystemColors::HotTrack;
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 446);
			this->Controls->Add(this->ctrl_tabs);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->ctrl_tabs->ResumeLayout(false);
			this->tab_inicio->ResumeLayout(false);
			this->tab_inicio->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tab_usuarios->ResumeLayout(false);
			this->tab_usuarios->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgrd_usuarios))->EndInit();
			this->tab_provedores->ResumeLayout(false);
			this->tab_provedores->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_provedores))->EndInit();
			this->tab_productos->ResumeLayout(false);
			this->tab_productos->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_productos))->EndInit();
			this->tab_cats_subcats->ResumeLayout(false);
			this->tab_cats_subcats->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_subcategorias))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_categorias))->EndInit();
			this->tab_ventas->ResumeLayout(false);
			this->tab_ventas->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_ventas))->EndInit();
			this->tab_realizar_venta->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtgv_realizar_venta))->EndInit();
			this->tab_miscelanea_->ResumeLayout(false);
			this->ctrl_tab_miscelanea->ResumeLayout(false);
			this->tab_web_browser->ResumeLayout(false);
			this->tab_web_browser->PerformLayout();
			this->tab_media_player->ResumeLayout(false);
			this->tab_media_player->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_volumen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wmp_media_player))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: void inicializacionPersonalizada(){
	
	this->conexion = gcnew PPx1::Conexion();
	this->mysql_conn = this->conexion->getConexion();
	this->productos_agregados = 1;

	refrescarTablaUsuarios();
	refrescarTablaProvedores();
	refrescarTablaCategorias();
	refrescarTablaSubcategorias();
	refrescarTablaProductos();
	refrescarTablaVentas();

	ArrayList^ cols = gcnew ArrayList();
	cols->Add("#");
	cols->Add("PRODUCTO");
	cols->Add("CANTIDAD");
	cols->Add("PRECIO UNITARIO");
	rellenarDatagrid(this->dtgv_realizar_venta, cols, nullptr);

	this->frm_agregar_producto = gcnew AgregarProducto();
	this->frm_agregar_producto->FormClosing += gcnew FormClosingEventHandler(this, &Inicio::frm_agregar_productoClosing);
	this->frm_agregar_producto->btn_aceptar->Click += gcnew EventHandler(this, &Inicio::btn_agregar_producto_ventaClick);
	this->frm_agregar_producto->btn_cancelar->Click += gcnew EventHandler(this, &Inicio::btn_cancelar_producto_ventaClick);

	this->tb_volumen->Value = this->wmp_media_player->settings->volume;
	this->lbl_volumen->Text = "volumen " + this->wmp_media_player->settings->volume;
}

		 System::Void btn_agregar_producto_ventaClick(Object^ o, EventArgs^ e){
			 int cantidad_prod = 0;
			 try{
				 cantidad_prod = Int32::Parse(this->frm_agregar_producto->txt_cantidad->Text);
				 String^ nombre_producto = this->frm_agregar_producto->cbx_producto->Items[this->frm_agregar_producto->cbx_producto->SelectedIndex]->ToString();
				 //mostrarError(nombre_producto);
				 mysql_conn->Open();
				 //obtener el precio del producto (puede cambiar con el tiempo)
				 MySqlCommand^ cmd = mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT precio FROM productos WHERE nombre=@nombre";
				 cmd->Parameters->AddWithValue("@nombre", nombre_producto);
				 MySqlDataReader^ res = nullptr;
				 try{
					 res = cmd->ExecuteReader();
					 if (res->Read())
					 {
						 DataGridViewRow^ row = gcnew DataGridViewRow();
						 DataGridViewTextBoxCell^ numero = gcnew DataGridViewTextBoxCell();
						 numero->Value = ""+(productos_agregados++);
						 DataGridViewTextBoxCell^ producto = gcnew DataGridViewTextBoxCell();
						 producto->Value = nombre_producto;
						 DataGridViewTextBoxCell^ cantidad = gcnew DataGridViewTextBoxCell();
						 cantidad->Value = "" + cantidad_prod;
						 DataGridViewTextBoxCell^ precio = gcnew DataGridViewTextBoxCell();
						 precio->Value = res->GetString(0);

						 row->Cells->Add(numero);
						 row->Cells->Add(producto);
						 row->Cells->Add(cantidad);
						 row->Cells->Add(precio);

						 this->dtgv_realizar_venta->Rows->Add(row);
					 }
				 }
				 catch (Exception^ ex){
					 mostrarError("Error: " + ex->Message);
					 delete ex;
				 }
				 finally{ mysql_conn->Close(); }
				 frm_agregar_productoClosing(this->frm_agregar_producto, gcnew FormClosingEventArgs(CloseReason::UserClosing,false));
			 }
			 catch (Exception^ ex){
				 mostrarError("Error: "+ex->Message);
				 delete ex;
			 }
		 }
		 System::Void btn_cancelar_producto_ventaClick(Object^ o, EventArgs^ e){
			 frm_agregar_productoClosing(this->frm_agregar_producto, gcnew FormClosingEventArgs(CloseReason::UserClosing, false));
		 }

public: void setId(int id_usuario){
			this->id_usuario = id_usuario;
			this->ctrl_tabs->Controls->Clear();
			//datos
			this->mysql_conn->Open();
			String^ sql = L"SELECT usuarios.id, usuario, nombre, ap_paterno, ap_materno, sexo, telefono" +
				", correo, rol, id_rol FROM usuarios,roles WHERE id_rol=roles.id AND usuarios.id=" + this->id_usuario;
			try{
				MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->mysql_conn);
				MySqlDataReader^ res = cmd->ExecuteReader();
				res->Read();
				if (res->HasRows)
				{
					this->lbl_usuario->Text = res->GetString(1);
					this->lbl_nombre->Text = res->GetString(2) + " " + res->GetString(3) + " " + res->GetString(4);
					this->lbl_sexo->Text = (res->GetChar(5) == 'H') ? "Hombre" : "Mujer";
					this->lbl_telefono->Text = res->GetString(6);
					this->lbl_correo->Text = res->GetString(7);
					this->lbl_rol->Text = res->GetString(8);
					int rol = res->GetInt32(9);
					this->ctrl_tabs->Controls->Add(this->tab_inicio);
					if (rol==1){//administrador
						this->ctrl_tabs->Controls->Add(this->tab_usuarios);
						this->ctrl_tabs->Controls->Add(this->tab_provedores);
						this->ctrl_tabs->Controls->Add(this->tab_productos);
						this->ctrl_tabs->Controls->Add(this->tab_cats_subcats);
						this->ctrl_tabs->Controls->Add(this->tab_ventas);
						this->ctrl_tabs->Controls->Add(this->tab_realizar_venta);
					}
					else if (rol==2){//vendedor
						this->ctrl_tabs->Controls->Add(this->tab_realizar_venta);
					}
					this->ctrl_tabs->Controls->Add(this->tab_miscelanea_);
				}
			}
			catch (Exception^e){
				MessageBox::Show("Ha ocurrido un error!.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				delete e;
			}
			finally{
				this->mysql_conn->Close();
			}
}

private: void refrescarTablaUsuarios(){
				this->dtgrd_usuarios->Rows->Clear();
				//conexion llenado de datos
				this->mysql_conn->Open();
				String^ sql = L"SELECT usuarios.id, rol, nombre, ap_paterno, ap_materno, sexo, telefono"
					+ ", correo, usuario, usuarios.fecha_creacion, entradas, fecha_ultima_entrada FROM usuarios, "
					+ "roles WHERE roles.id=usuarios.id_rol "+this->usuarios_filtro_busqueda+this->usuarios_orderby;
				try{
					MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->mysql_conn);
					MySqlDataReader^ res = cmd->ExecuteReader();
					ArrayList^ columnas_user = gcnew ArrayList();
					columnas_user->Add(gcnew String("ID"));
					columnas_user->Add(gcnew String("ROL"));
					columnas_user->Add(gcnew String("NOMBRE"));
					columnas_user->Add(gcnew String("APELLIDO PATERNO"));
					columnas_user->Add(gcnew String("APELLIDO MATERNO"));
					columnas_user->Add(gcnew String("SEXO"));
					columnas_user->Add(gcnew String("TELEFONO"));
					columnas_user->Add(gcnew String("CORREO"));
					columnas_user->Add(gcnew String("USUARIO"));
					columnas_user->Add(gcnew String("FECHA DE CREACION"));
					columnas_user->Add(gcnew String("ENTRADAS"));
					columnas_user->Add(gcnew String("ULTIMA ENTRADA"));
					rellenarDatagrid(this->dtgrd_usuarios,columnas_user, res);
				}
				catch (Exception^e){
					MessageBox::Show("Ha ocurrido un error!."+e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//						 throw e;
				}
				finally{
					this->mysql_conn->Close();
				}
				//poner los que solo seran leidos y no cambiados
				this->dtgrd_usuarios->Columns[9]->ReadOnly = true;
				this->dtgrd_usuarios->Columns[10]->ReadOnly = true;
				this->dtgrd_usuarios->Columns[11]->ReadOnly = true;
}
private: System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
}
private: System::Void btn_refrescar_Click(System::Object^  sender, System::EventArgs^  e) {
			 refrescarTablaUsuarios();
}

private: void rellenarDatagrid(DataGridView^ dt, ArrayList^ cols, MySqlDataReader^ res){
			 dt->Columns->Clear();
			 dt->Rows->Clear();
			 IEnumerator^ ens = cols->GetEnumerator();
			 int cont = 0;
			 while (ens->MoveNext())
			 {
				 DataGridViewTextBoxColumn^ c = gcnew DataGridViewTextBoxColumn();
				 if (cont == 0)
					 c->ReadOnly = true;
				 c->HeaderText = ens->Current->ToString();
				 c->CellTemplate = gcnew DataGridViewTextBoxCell();				 
				 c->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
				 dt->Columns->Add(c);
				 cont++;
			 }
			 if (res){
				 while (res->Read())
				 {
					 DataGridViewRow^ row = gcnew DataGridViewRow();
					 for (int i = 0; i < cols->Count; i++)
					 {
						 DataGridViewCell^ cell = gcnew DataGridViewTextBoxCell();
						 cell->Value = res->GetString(i);
						 row->Cells->Add(cell);
					 }
					 dt->Rows->Add(row);
				 }
			 }
}

private: System::Void dtgrd_usuarios_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {		
			 int columna = e->ColumnIndex;	
			 ArrayList ^nombre_columnas = gcnew ArrayList();
			 String^ nuevo_valor = this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[columna]->Value->ToString();
			 nombre_columnas->Add("id");
			 nombre_columnas->Add("id_rol");
			 nombre_columnas->Add("nombre");
			 nombre_columnas->Add("ap_paterno");
			 nombre_columnas->Add("ap_materno");
			 nombre_columnas->Add("sexo");
			 nombre_columnas->Add("telefono");
			 nombre_columnas->Add("correo");
			 nombre_columnas->Add("usuario");
			 String^ id = this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[0]->Value->ToString();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 //cmd->CommandType = CommandType::TableDirect;
			 MySqlDataReader^ res = nullptr;
			 if (columna == 1){
				 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
				 valor->Value = this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				 this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
				 cmd->Prepare();
				 cmd->CommandText = "SELECT id FROM roles WHERE rol=@valor";
				 try{
					 cmd->Parameters->AddWithValue("@valor", nuevo_valor);
					 res = cmd->ExecuteReader();
					 if (res->HasRows)
					 {
						 res->Read();
						 String^ id_rol = gcnew String(res->GetString(0));
						 mysql_conn->Close();
						 mysql_conn->Open();
						 cmd->CommandText = "UPDATE usuarios SET id_rol=@id_rol WHERE id=@id";
						 cmd->Parameters->Clear();
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id_rol", id_rol);
						 cmd->Parameters->AddWithValue("@id", id);
						 cmd->ExecuteNonQuery();
					 }
				 }
				 catch (Exception^ ex){/*captura de error*/
					 mostrarError("Ha ocurrido un error: "+ex->Message);
					 delete ex;
				 }
			 }
			 else{
				cmd->Parameters->Clear();
				cmd->Prepare();
				cmd->CommandText = L"UPDATE usuarios SET "+nombre_columnas[columna]+"=@nuevo_valor WHERE id=@id";
				
				cmd->Parameters->AddWithValue("@nuevo_valor", nuevo_valor);
				cmd->Parameters->AddWithValue("@id", id);
				cmd->ExecuteNonQuery();
				if (columna==5)
				{
					DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
					valor->Value = this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
					this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
				}
				//mostrarError(nuevo_valor+" "+id+ cmd->CommandText+" "+cmd->Parameters->Count);
			 }
			 mysql_conn->Close();
}
private: System::Void btn_agregar_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewRow^ row = gcnew DataGridViewRow();
			 DateTime hoy = DateTime::Now;
			 String^ fecha = hoy.Year+"-"+hoy.Month.ToString()+"-"+hoy.Day;
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 cmd->CommandText = L"INSERT INTO usuarios(id_rol,fecha_ultima_entrada,fecha_creacion,usuario, nombre)"
				 + " VALUES('2','" + fecha + "','" + fecha + "','" + fecha + "','" + fecha + "')";
			 cmd->ExecuteNonQuery();
			 mysql_conn->Close();
			 refrescarTablaUsuarios();
}
private: System::Void btn_eliminar_usuario_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection^ rows = this->dtgrd_usuarios->SelectedRows;
			 if (rows->Count)
			 {
				  Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar esos registros?","Confirmacion",
					 MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				  if (conf == Windows::Forms::DialogResult::Yes){
					  mysql_conn->CreateCommand();
					  MySqlCommand^ cmd = mysql_conn->CreateCommand();
					  for each (DataGridViewRow^ row in rows)
					  {
						  mysql_conn->Open();
						  cmd->CommandText = L"DELETE FROM usuarios WHERE id=@id";
						  cmd->Prepare();
						  cmd->Parameters->Clear();
						  cmd->Parameters->AddWithValue("@id", row->Cells[0]->Value);
						  try{
							  cmd->ExecuteNonQuery();
						  }
						  catch (Exception^ ex){
							  mostrarError("Error: " + ex->Message);
							  delete ex;
						  }
						  finally{
							  mysql_conn->Close();
						  }
					  }
					  refrescarTablaUsuarios();
				  }
			 }
}
private: System::Void dtgrd_usuarios_CellBeginEdit(System::Object^  sender, DataGridViewCellCancelEventArgs^  e) {
			 int index = e->ColumnIndex;
			 if (index == 1){
				 DataGridViewComboBoxCell^ combo = gcnew DataGridViewComboBoxCell();
				 //obtener los roles desde la bd
				 this->mysql_conn->Open();
				 String^ sql = L"SELECT rol FROM roles";
				 try{
					 MySqlCommand^ cmd = this->mysql_conn->CreateCommand();
					 MySqlDataReader^ res = cmd->ExecuteReader();
					 while (res->Read())
					 {
						 combo->Items->Add(res->GetString(0));
					 }
				 }
				 catch (Exception^e){
					 mostrarError("Error: " + e->Message);
					 delete e;
				 }
				 finally{
					 this->mysql_conn->Close();
				 }
				 this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex] = combo;
			 }
			 else if (index == 5){
				 DataGridViewComboBoxCell^ combo_sexo = gcnew DataGridViewComboBoxCell();
				 combo_sexo->Items->Add("H");
				 combo_sexo->Items->Add("M");
				 this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex] = combo_sexo;
			 }
}

private: void mostrarError(String^ err){
			 MessageBox::Show(err,"Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
}

private: System::Void cbx_filtro_usuario_SelectedIndexChanged(System::Object^  sender, EventArgs^  e) {
			 ArrayList ^items = gcnew ArrayList();
			 items->Add("usuarios.id");
			 items->Add("id_rol");
			 items->Add("nombre");
			 items->Add("ap_paterno");
			 items->Add("ap_materno");
			 items->Add("sexo");
			 items->Add("telefono");
			 items->Add("correo");
			 items->Add("entradas");
			 items->Add("usuario");
			 items->Add("fecha_ultima_entrada");
			 items->Add("fecha_creacion");
			 this->usuarios_orderby = "ORDER BY " + items[this->cbx_filtro_usuario->SelectedIndex];
			 refrescarTablaUsuarios();
}
private: System::Void btn_buscar_usuario_Click(System::Object^  sender, EventArgs^  e) {
			 this->usuarios_filtro_busqueda = "AND CONCAT(usuarios.id,' ',roles.rol,' ',nombre,' ',ap_paterno,' ',ap_materno"
				 + ",' ',sexo,' ',telefono,' ',correo,' ',entradas,' ',fecha_ultima_entrada,' ',usuario,' ',usuarios.fecha_creacion) like '%"
				 + this->txt_buscar_usuario->Text + "%' ";
			 refrescarTablaUsuarios();
}
private: System::Void txt_buscar_usuario_KeyUp(System::Object^  sender, KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_buscar_usuario_Click(nullptr, EventArgs::Empty);
			 }
}

		 void refrescarTablaProvedores(){
			 this->dtgv_provedores->Rows->Clear();
			 //conexion llenado de datos
			 this->mysql_conn->Open();
			 String^ sql = L"SELECT id,nombre,telefono,correo,direccion FROM provedores " + this->provedores_filtro_busqueda + this->provedores_orderby;
			 try{
				 MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->mysql_conn);
				 MySqlDataReader^ res = cmd->ExecuteReader();
				 ArrayList^ columnas_user = gcnew ArrayList();
				 columnas_user->Add(gcnew String("ID"));
				 columnas_user->Add(gcnew String("NOMBRE"));
				 columnas_user->Add(gcnew String("TELEFONO"));
				 columnas_user->Add(gcnew String("CORREO"));
				 columnas_user->Add(gcnew String("DIRECCION"));
				 rellenarDatagrid(this->dtgv_provedores, columnas_user, res);
			 }
			 catch (Exception^e){
				 MessageBox::Show("Ha ocurrido un error!." + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 //						 throw e;
			 }
			 finally{
				 this->mysql_conn->Close();
			 }
		 }

private: System::Void dtgv_provedores_CellValueChanged(System::Object^  sender, DataGridViewCellEventArgs^  e) {
			 int columna = e->ColumnIndex;
			 ArrayList ^nombre_columnas = gcnew ArrayList();
			 String^ nuevo_valor = this->dtgv_provedores->Rows[e->RowIndex]->Cells[columna]->Value->ToString();
			 nombre_columnas->Add("id");
			 nombre_columnas->Add("nombre");
			 nombre_columnas->Add("telefono");
			 nombre_columnas->Add("correo");
			 nombre_columnas->Add("direccion");
			 String^ id = this->dtgv_provedores->Rows[e->RowIndex]->Cells[0]->Value->ToString();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			cmd->Prepare();
			cmd->CommandText = L"UPDATE provedores SET " + nombre_columnas[columna] + "=@nuevo_valor WHERE id=@id";

			cmd->Parameters->AddWithValue("@nuevo_valor", nuevo_valor);
			cmd->Parameters->AddWithValue("@id", id);
			cmd->ExecuteNonQuery();
			 mysql_conn->Close();
}
private: System::Void btn_agregar_provedor_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewRow^ row = gcnew DataGridViewRow();
			 DateTime hoy = DateTime::Now;
			 String^ fecha = hoy.Year + "-" + hoy.Month.ToString() + "-" + hoy.Day;
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 cmd->CommandText = L"INSERT INTO provedores(nombre,telefono,correo,direccion)"
				 + " VALUES('" + fecha + "','','','')";
			 cmd->ExecuteNonQuery();
			 mysql_conn->Close();
			 refrescarTablaProvedores();
}
private: System::Void btn_eliminar_provedor_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection^ rows = this->dtgv_provedores->SelectedRows;
			 if (rows->Count)
			 {
				 Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar esos registros?", "Confirmacion",
					 MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				 if (conf == Windows::Forms::DialogResult::Yes){
					 mysql_conn->CreateCommand();
					 MySqlCommand^ cmd = mysql_conn->CreateCommand();
					 for each (DataGridViewRow^ row in rows)
					 {
						 mysql_conn->Open();
						 cmd->CommandText = L"DELETE FROM provedores WHERE id=@id";
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id", row->Cells[0]->Value);
						 try{
							 cmd->ExecuteNonQuery();
						 }
						 catch (Exception^ ex){
							 mostrarError("Error: " + ex->Message);
							 delete ex;
						 }
						 finally{
							 mysql_conn->Close();
						 }
					 }
					 refrescarTablaProvedores();
				 }
			 }
}
private: System::Void btn_refrescar_provedores_Click(System::Object^  sender, System::EventArgs^  e) {
			 refrescarTablaProvedores();
}
private: System::Void cbx_filtro_provedor_SelectedIndexChanged(System::Object^  sender, EventArgs^  e) {
			 ArrayList ^items = gcnew ArrayList();
			 items->Add("id");
			 items->Add("nombre");
			 items->Add("telefono");
			 items->Add("correo");
			 items->Add("direccion");
			 this->provedores_orderby = "ORDER BY " + items[this->cbx_filtro_provedor->SelectedIndex];
			 refrescarTablaProvedores();
}
private: System::Void btn_buscar_provedores_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->provedores_filtro_busqueda = "WHERE CONCAT(id,' ',nombre,' ',telefono,' ',correo,' ',direccion) like '%"
				 + this->txt_buscar_provedor->Text + "%' ";
			 refrescarTablaProvedores();
}
private: System::Void txt_buscar_provedor_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_buscar_provedores_Click(nullptr, EventArgs::Empty);
			 }
}

		 void refrescarTablaCategorias(){
			 this->dtgv_categorias->Rows->Clear();
			 //conexion llenado de datos
			 this->mysql_conn->Open();
			 try{
				 MySqlCommand^ cmd = this->mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT id,categoria FROM categorias " + this->categorias_filtro_busqueda;
				 MySqlDataReader^ res = cmd->ExecuteReader();
				 ArrayList^ columnas_user = gcnew ArrayList();
				 columnas_user->Add(gcnew String("ID"));
				 columnas_user->Add(gcnew String("CATEGORIA"));
				 rellenarDatagrid(this->dtgv_categorias, columnas_user, res);
			 }
			 catch (Exception^e){
				 MessageBox::Show("Ha ocurrido un error!." + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 //						 throw e;
			 }
			 finally{
				 this->mysql_conn->Close();
			 }
		 }

private: System::Void btn_agregar_categoria_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewRow^ row = gcnew DataGridViewRow();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 cmd->CommandText = L"INSERT INTO categorias VALUES(NULL,'')";
			 cmd->ExecuteNonQuery();
			 mysql_conn->Close();
			 refrescarTablaCategorias();
}
private: System::Void btn_eliminar_categoria_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection^ rows = this->dtgv_categorias->SelectedRows;
			 if (rows->Count)
			 {
				 Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar esos registros?", "Confirmacion",
					 MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				 if (conf == Windows::Forms::DialogResult::Yes){
					 mysql_conn->CreateCommand();
					 MySqlCommand^ cmd = mysql_conn->CreateCommand();
					 for each (DataGridViewRow^ row in rows)
					 {
						 mysql_conn->Open();
						 cmd->CommandText = L"DELETE FROM categorias WHERE id=@id";
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id", row->Cells[0]->Value);
						 try{
							 cmd->ExecuteNonQuery();
						 }
						 catch (Exception^ ex){
							 mostrarError("Error: " + ex->Message);
							 delete ex;
						 }
						 finally{
							 mysql_conn->Close();
						 }
					 }
					 refrescarTablaCategorias();
				 }
			 }
}
private: System::Void btn_refrescar_categorias_Click(System::Object^  sender, System::EventArgs^  e) {
			 refrescarTablaCategorias();
}
private: System::Void btn_buscar_categoria_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->categorias_filtro_busqueda = "WHERE CONCAT(id,' ',categoria) like '%"
				 + this->txt_buscar_categoria->Text + "%' ";
			 refrescarTablaCategorias();
}
private: System::Void txt_buscar_categoria_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_buscar_categoria_Click(nullptr, EventArgs::Empty);
			 }
}
private: System::Void dtgv_categorias_CellValueChanged(System::Object^  sender, DataGridViewCellEventArgs^  e) {
			 int columna = e->ColumnIndex;
			 ArrayList ^nombre_columnas = gcnew ArrayList();
			 String^ nuevo_valor = this->dtgv_categorias->Rows[e->RowIndex]->Cells[columna]->Value->ToString();
			 nombre_columnas->Add("id");
			 nombre_columnas->Add("categoria");
			 String^ id = this->dtgv_categorias->Rows[e->RowIndex]->Cells[0]->Value->ToString();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 cmd->Prepare();
			 cmd->CommandText = L"UPDATE categorias SET " + nombre_columnas[columna] + "=@nuevo_valor WHERE id=@id";
			 cmd->Parameters->AddWithValue("@nuevo_valor", nuevo_valor);
			 cmd->Parameters->AddWithValue("@id", id);
			 cmd->ExecuteNonQuery();
			 mysql_conn->Close();
}

		 void refrescarTablaSubcategorias(){
			 this->dtgv_subcategorias->Rows->Clear();
			 //conexion llenado de datos
			 this->mysql_conn->Open();
			 try{
				 MySqlCommand^ cmd = this->mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT subcategorias.id,categoria,subcategoria FROM categorias,subcategorias "
					 + "WHERE categorias.id=id_categoria " + this->subcategorias_filtro_busqueda;
				 MySqlDataReader^ res = cmd->ExecuteReader();
				 ArrayList^ columnas_user = gcnew ArrayList();
				 columnas_user->Add(gcnew String("ID"));
				 columnas_user->Add(gcnew String("CATEGORIA"));
				 columnas_user->Add(gcnew String("SUBCATEGORIA"));
				 rellenarDatagrid(this->dtgv_subcategorias, columnas_user, res);
			 }
			 catch (Exception^e){
				 MessageBox::Show("Ha ocurrido un error!." + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 //						 throw e;
			 }
			 finally{
				 this->mysql_conn->Close();
			 }
		 }

private: System::Void btn_agregar_subcategoria_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewRow^ row = gcnew DataGridViewRow();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 cmd->CommandText = L"SELECT id FROM categorias";
			 MySqlDataReader^ res = cmd->ExecuteReader();
			 if (res->Read())
			 {
				 cmd->CommandText = L"INSERT INTO subcategorias VALUES(NULL,@cat,'')";
				 cmd->Prepare();
				 cmd->Parameters->AddWithValue("@cat", res->GetString(0));
				 this->mysql_conn->Close();
				 this->mysql_conn->Open();
				 cmd->ExecuteNonQuery();
			 }			 
			 mysql_conn->Close();
			 refrescarTablaSubcategorias();
}
private: System::Void btn_eliminar_subcategoria_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection^ rows = this->dtgv_subcategorias->SelectedRows;
			 if (rows->Count)
			 {
				 Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar esos registros?", "Confirmacion",
					 MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				 if (conf == Windows::Forms::DialogResult::Yes){
					 mysql_conn->CreateCommand();
					 MySqlCommand^ cmd = mysql_conn->CreateCommand();
					 for each (DataGridViewRow^ row in rows)
					 {
						 mysql_conn->Open();
						 cmd->CommandText = L"DELETE FROM subcategorias WHERE id=@id";
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id", row->Cells[0]->Value);
						 try{
							 cmd->ExecuteNonQuery();
						 }
						 catch (Exception^ ex){
							 mostrarError("Error: " + ex->Message);
							 delete ex;
						 }
						 finally{
							 mysql_conn->Close();
						 }
					 }
					 refrescarTablaSubcategorias();
				 }
			 }
}
private: System::Void btn_refrescar_subcategoria_Click(System::Object^  sender, System::EventArgs^  e) {
			 refrescarTablaSubcategorias();
}
private: System::Void dtgv_subcategorias_CellValueChanged(System::Object^  sender, DataGridViewCellEventArgs^  e) {
			 int columna = e->ColumnIndex;
			 ArrayList ^nombre_columnas = gcnew ArrayList();
			 String^ nuevo_valor = this->dtgv_subcategorias->Rows[e->RowIndex]->Cells[columna]->Value->ToString();
			 nombre_columnas->Add("id");
			 nombre_columnas->Add("id_categoria");
			 nombre_columnas->Add("subcategoria");
			 String^ id = this->dtgv_subcategorias->Rows[e->RowIndex]->Cells[0]->Value->ToString();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 //cmd->CommandType = CommandType::TableDirect;
			 MySqlDataReader^ res = nullptr;
			 if (columna == 1){
				 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
				 valor->Value = this->dtgv_subcategorias->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				 this->dtgv_subcategorias->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
				 cmd->Prepare();
				 cmd->CommandText = "SELECT id FROM categorias WHERE categoria=@valor";
				 try{
					 cmd->Parameters->AddWithValue("@valor", nuevo_valor);
					 res = cmd->ExecuteReader();
					 if (res->HasRows)
					 {
						 res->Read();
						 String^ id_cat = gcnew String(res->GetString(0));
						 mysql_conn->Close();
						 mysql_conn->Open();
						 cmd->CommandText = "UPDATE subcategorias SET id_categoria=@id_cat WHERE id=@id";
						 cmd->Parameters->Clear();
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id_cat", id_cat);
						 cmd->Parameters->AddWithValue("@id", id);
						 cmd->ExecuteNonQuery();
					 }
				 }
				 catch (Exception^ ex){/*captura de error*/
					 mostrarError("Ha ocurrido un error: " + ex->Message);
					 delete ex;
				 }
			 }
			 else{
				 cmd->Parameters->Clear();
				 cmd->Prepare();
				 cmd->CommandText = L"UPDATE subcategorias SET " + nombre_columnas[columna] + "=@nuevo_valor WHERE id=@id";

				 cmd->Parameters->AddWithValue("@nuevo_valor", nuevo_valor);
				 cmd->Parameters->AddWithValue("@id", id);
				 cmd->ExecuteNonQuery();
				 if (columna == 5)
				 {
					 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
					 valor->Value = this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
					 this->dtgrd_usuarios->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
				 }
				 //mostrarError(nuevo_valor+" "+id+ cmd->CommandText+" "+cmd->Parameters->Count);
			 }
			 mysql_conn->Close();
}
private: System::Void btn_buscar_subcategorias_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->subcategorias_filtro_busqueda = "AND CONCAT(subcategorias.id,' ',categoria,' ',subcategoria) like '%"
				 + this->txt_buscar_subcategorias->Text + "%' ";
			 refrescarTablaSubcategorias();
}
private: System::Void txt_buscar_subcategorias_KeyUp(System::Object^  sender, KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_buscar_subcategorias_Click(nullptr, EventArgs::Empty);
			 }
}
private: System::Void dtgv_subcategorias_CellBeginEdit(System::Object^  sender, DataGridViewCellCancelEventArgs^  e) {
			 if (e->ColumnIndex == 1)
			 {
				 DataGridViewComboBoxCell^ combo = gcnew DataGridViewComboBoxCell();
				 //obtener los roles desde la bd
				 this->mysql_conn->Open();
				 try{
					 MySqlCommand^ cmd = this->mysql_conn->CreateCommand();
					 cmd->CommandText = L"SELECT categoria FROM categorias";
					 MySqlDataReader^ res = cmd->ExecuteReader();
					 while (res->Read())
					 {
						 combo->Items->Add(res->GetString(0));
					 }
				 }
				 catch (Exception^e){
					 mostrarError("Error: " + e->Message);
					 delete e;
				 }
				 finally{
					 this->mysql_conn->Close();
				 }
				 this->dtgv_subcategorias->Rows[e->RowIndex]->Cells[e->ColumnIndex] = combo;
			 }
}

private: System::Void btn_agregar_producto_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->frm_agregar_producto->ShowDialog(this);
}

System::Void frm_agregar_productoClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {	  
		this->frm_agregar_producto->Hide();
		e->Cancel = true;
}

		 void refrescarTablaProductos(){
			 this->dtgv_productos->Rows->Clear();
			 //conexion llenado de datos
			 this->mysql_conn->Open();
			 try{
				 MySqlCommand^ cmd = this->mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT productos.id,categoria,subcategoria,provedores.nombre,productos.nombre,precio,descripcion,existencia "
					 + "FROM productos,categorias,subcategorias,provedores WHERE subcategorias.id_categoria=categorias.id AND "
					 + "productos.id_subcategoria=subcategorias.id AND provedores.id=productos.id_provedor "
					 + this->productos_filtro_busqueda + this->productos_orderby;
				 MySqlDataReader^ res = cmd->ExecuteReader();
				 ArrayList^ columnas_user = gcnew ArrayList();
				 columnas_user->Add(gcnew String("ID"));
				 columnas_user->Add(gcnew String("CATEGORIA"));
				 columnas_user->Add(gcnew String("SUBCATEGORIA"));
				 columnas_user->Add(gcnew String("PROVEDOR"));
				 columnas_user->Add(gcnew String("NOMBRE"));
				 columnas_user->Add(gcnew String("PRECIO"));
				 columnas_user->Add(gcnew String("DESCRIPCION"));
				 columnas_user->Add(gcnew String("EXISTENCIA"));
				 rellenarDatagrid(this->dtgv_productos, columnas_user, res);
			 }
			 catch (Exception^e){
				 MessageBox::Show("Ha ocurrido un error!." + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 //						 throw e;
			 }
			 finally{
				 this->mysql_conn->Close();
			 }
			 this->dtgv_productos->Columns[1]->ReadOnly = true;
		 }

private: System::Void btn_agregar_productos_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewRow^ row = gcnew DataGridViewRow();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 cmd->CommandText = L"SELECT id FROM subcategorias";
			 MySqlDataReader^ res = cmd->ExecuteReader();
			 if (res->Read())
			 {
				 String^ subcatid = gcnew String( res->GetString(0));
				 cmd->CommandText = L"SELECT id FROM provedores";
				 mysql_conn->Close();
				 mysql_conn->Open();
				 res = cmd->ExecuteReader();
				 if (res->Read())
				 {
					 String^ providerid = gcnew String(res->GetString(0));
					 this->mysql_conn->Close();
					 this->mysql_conn->Open();
					 cmd->CommandText = L"INSERT INTO productos VALUES(NULL,@subcat,@provedor,'',0,'',0)";
					 cmd->Prepare();
					 cmd->Parameters->AddWithValue("@subcat", subcatid);
					 cmd->Parameters->AddWithValue("@provedor", providerid);
					 cmd->ExecuteNonQuery();
				 }
				 else{
					 mostrarError("Debe haber al menos un provedor para agregar un producto");
				 }
			 }
			 else{
				 mostrarError("Actualmente no hay ninguna subcategoria. Agregue una subcategoria para poder agregar productos.");
			 }
			 mysql_conn->Close();
			 refrescarTablaProductos();
}
private: System::Void btn_refrescar_productos_Click(System::Object^  sender, System::EventArgs^  e) {
			 refrescarTablaProductos();
}
private: System::Void btn_eliminar_productos_Click(System::Object^  sender, System::EventArgs^  e) {
		DataGridViewSelectedRowCollection^ rows = this->dtgv_productos->SelectedRows;
		if (rows->Count)
		{
			Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar esos registros?", "Confirmacion",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (conf == Windows::Forms::DialogResult::Yes){
				mysql_conn->CreateCommand();
				MySqlCommand^ cmd = mysql_conn->CreateCommand();
				for each (DataGridViewRow^ row in rows)
				{
					mysql_conn->Open();
					cmd->CommandText = L"DELETE FROM productos WHERE id=@id";
					cmd->Prepare();
					cmd->Parameters->Clear();
					cmd->Parameters->AddWithValue("@id", row->Cells[0]->Value);
					try{
						cmd->ExecuteNonQuery();
					}
					catch (Exception^ ex){
						mostrarError("Error: " + ex->Message);
						delete ex;
					}
					finally{
						mysql_conn->Close();
					}
				}
				refrescarTablaProductos();
			}
		}
}
private: System::Void btn_buscar_productos_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->productos_filtro_busqueda = "AND CONCAT(productos.id,' ',categoria,' ',subcategoria,' ',provedores.nombre,' '"
				 +",productos.nombre,' ',precio,' ',descripcion,' ',existencia) like '%"
				 + this->txt_filtro_buscar_productos->Text + "%' ";
			 refrescarTablaProductos();
}
private: System::Void txt_filtro_buscar_productos_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_buscar_productos_Click(nullptr, EventArgs::Empty);
			 }
}
private: System::Void cbx_filtro_productos_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 ArrayList ^items = gcnew ArrayList();
			 items->Add("productos.id");
			 items->Add("categoria");
			 items->Add("subcategoria");
			 items->Add("provedores.nombre");
			 items->Add("productos.nombre");
			 items->Add("precio");
			 items->Add("descripcion");
			 items->Add("existencia");
			 this->provedores_orderby = "ORDER BY " + items[this->cbx_filtro_productos->SelectedIndex];
			 refrescarTablaProductos();
}
private: System::Void dtgv_productos_CellValueChanged(System::Object^  sender, DataGridViewCellEventArgs^  e) {
			 int columna = e->ColumnIndex;
			 ArrayList ^nombre_columnas = gcnew ArrayList();
			 String^ nuevo_valor = this->dtgv_productos->Rows[e->RowIndex]->Cells[columna]->Value->ToString();
			 nombre_columnas->Add("id");
			 nombre_columnas->Add("");
			 nombre_columnas->Add("id_categoria");
			 nombre_columnas->Add("id_provedor");
			 nombre_columnas->Add("nombre");
			 nombre_columnas->Add("precio");
			 nombre_columnas->Add("descripcion");
			 nombre_columnas->Add("existencia");
			 String^ id = this->dtgv_productos->Rows[e->RowIndex]->Cells[0]->Value->ToString();
			 mysql_conn->Open();
			 MySqlCommand^ cmd = mysql_conn->CreateCommand();
			 //cmd->CommandType = CommandType::TableDirect;
			 MySqlDataReader^ res = nullptr;
			 if (columna == 2){
				 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
				 valor->Value = this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				 this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
				 cmd->Prepare();
				 cmd->CommandText = "SELECT id FROM subcategorias WHERE subcategoria=@valor";
				 try{
					 cmd->Parameters->AddWithValue("@valor", nuevo_valor);
					 res = cmd->ExecuteReader();
					 if (res->HasRows)
					 {
						 res->Read();
						 String^ id_rol = gcnew String(res->GetString(0));
						 mysql_conn->Close();
						 mysql_conn->Open();
						 cmd->CommandText = "UPDATE productos SET id_subcategoria=@id_subcat WHERE id=@id";
						 cmd->Parameters->Clear();
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id_subcat", id_rol);
						 cmd->Parameters->AddWithValue("@id", id);
						 cmd->ExecuteNonQuery();
					 }
				 }
				 catch (Exception^ ex){/*captura de error*/
					 mostrarError("Ha ocurrido un error: " + ex->Message);
					 delete ex;
				 }
			 }
			 else if (columna == 3){
				 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
				 valor->Value = this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				 this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
				 cmd->Prepare();
				 cmd->CommandText = "SELECT id FROM provedores WHERE nombre=@valor";
				 try{
					 cmd->Parameters->AddWithValue("@valor", nuevo_valor);
					 res = cmd->ExecuteReader();
					 if (res->HasRows)
					 {
						 res->Read();
						 String^ id_rol = gcnew String(res->GetString(0));
						 mysql_conn->Close();
						 mysql_conn->Open();
						 cmd->CommandText = "UPDATE productos SET id_provedor=@id_provedor WHERE id=@id";
						 cmd->Parameters->Clear();
						 cmd->Prepare();
						 cmd->Parameters->AddWithValue("@id_provedor", id_rol);
						 cmd->Parameters->AddWithValue("@id", id);
						 cmd->ExecuteNonQuery();
					 }
				 }
				 catch (Exception^ ex){/*captura de error*/
					 mostrarError("Ha ocurrido un error: " + ex->Message);
					 delete ex;
				 }
			 }
			 else{
				 cmd->Parameters->Clear();
				 cmd->Prepare();
				 cmd->CommandText = L"UPDATE productos SET " + nombre_columnas[columna] + "=@nuevo_valor WHERE id=@id";
				 cmd->Parameters->AddWithValue("@nuevo_valor", nuevo_valor);
				 cmd->Parameters->AddWithValue("@id", id);
				 cmd->ExecuteNonQuery();
				 //mostrarError(nuevo_valor+" "+id+ cmd->CommandText+" "+cmd->Parameters->Count);
			 }
			 mysql_conn->Close();
			 if (columna == 2)
			 {
				 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
				 valor->Value = this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				 this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
			 }
			 else if (columna == 3)
			 {
				 DataGridViewTextBoxCell^ valor = gcnew DataGridViewTextBoxCell();
				 valor->Value = this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
				 this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex] = valor;
			 }
}
private: System::Void dtgv_productos_CellBeginEdit(System::Object^  sender, DataGridViewCellCancelEventArgs^  e) {
			 int index = e->ColumnIndex;
			 MySqlCommand^ cmd = nullptr;
			 if (index == 2)
			 {
				 DataGridViewComboBoxCell^ combo = gcnew DataGridViewComboBoxCell();
				 mysql_conn->Open();
				 cmd = mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT subcategoria FROM subcategorias";
				 try{
					 MySqlDataReader^ res = cmd->ExecuteReader();
					 while (res->Read())
					 {
						 combo->Items->Add(res->GetString(0));
					 }
				 }
				 catch (Exception^ ex){
					 mostrarError("Error: " + ex->Message);
					 delete ex;
				 }
				 finally{
					 mysql_conn->Close();
				 }
				 this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex] = combo;
			 }
			 else if (index == 3)
			 {
				 DataGridViewComboBoxCell^ combo = gcnew DataGridViewComboBoxCell();
				 mysql_conn->Open();
				 cmd = mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT nombre FROM provedores";
				 try{
					 MySqlDataReader^ res = cmd->ExecuteReader();
					 while (res->Read())
					 {
						 combo->Items->Add(res->GetString(0));
					 }
				 }
				 catch (Exception^ ex){
					 mostrarError("Error: " + ex->Message);
					 delete ex;
				 }
				 finally{
					 mysql_conn->Close();
				 }
				 this->dtgv_productos->Rows[e->RowIndex]->Cells[e->ColumnIndex] = combo;
}
}

		 void refrescarTablaVentas(){
			 this->dtgv_ventas->Rows->Clear();
			 //conexion llenado de datos
			 this->mysql_conn->Open();
			 try{
				 MySqlCommand^ cmd = this->mysql_conn->CreateCommand();
				 cmd->CommandText = L"SELECT id,fecha,nota FROM ventas " + this->ventas_filtro_busqueda+this->ventas_orderby;
				 MySqlDataReader^ res = cmd->ExecuteReader();
				 ArrayList^ columnas_user = gcnew ArrayList();
				 columnas_user->Add(gcnew String("ID"));
				 columnas_user->Add(gcnew String("FECHA"));
				 columnas_user->Add(gcnew String("NOTA"));
				 rellenarDatagrid(this->dtgv_ventas, columnas_user, res);
			 }
			 catch (Exception^e){
				 mostrarError("Ha ocurrido un error!." + e->Message);
				 delete e;
			 }
			 finally{
				 this->mysql_conn->Close();
			 }
			 this->dtgv_ventas->Columns[1]->ReadOnly = true;
		 }

private: System::Void btn_refrescar_ventas_Click(System::Object^  sender, System::EventArgs^  e) {
			 refrescarTablaVentas();
}
private: System::Void btn_agregar_venta_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ctrl_tabs->SelectTab(6);
}
private: System::Void btn_eliminar_ventas_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection^ rows = this->dtgv_ventas->SelectedRows;
			 if (rows->Count)
			 {
				 Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar estos registros?", "Confirmacion",
					 MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				 if (conf == Windows::Forms::DialogResult::Yes){
					 mysql_conn->CreateCommand();
					 MySqlCommand^ cmd = mysql_conn->CreateCommand();
					 for each (DataGridViewRow^ row in rows)
					 {
						 mysql_conn->Open();
						 cmd->CommandText = L"DELETE FROM ventas WHERE id=@id";
						 cmd->Prepare();
						 cmd->Parameters->Clear();
						 cmd->Parameters->AddWithValue("@id", row->Cells[0]->Value);
						 try{
							 cmd->ExecuteNonQuery();
						 }
						 catch (Exception^ ex){
							 mostrarError("Error: " + ex->Message);
							 delete ex;
						 }
						 finally{
							 mysql_conn->Close();
						 }
					 }
					 refrescarTablaProductos();
				 }
			 }
}
private: System::Void dtgv_ventas_CellValueChanged(System::Object^  sender, DataGridViewCellEventArgs^  e) {
			 //solo se cambiaran las notas
			int columna = e->ColumnIndex;
			if (columna == 2){//columna de nota
				 String^ nuevo_valor = this->dtgv_ventas->Rows[e->RowIndex]->Cells[columna]->Value->ToString();
				 String^ id = this->dtgv_ventas->Rows[e->RowIndex]->Cells[0]->Value->ToString();
				 mysql_conn->Open();
				 MySqlCommand^ cmd = mysql_conn->CreateCommand();
				 cmd->Prepare();
				 cmd->CommandText = L"UPDATE ventas SET nota=@nuevo_valor WHERE id=@id";
				 cmd->Parameters->AddWithValue("@nuevo_valor", nuevo_valor);
				 cmd->Parameters->AddWithValue("@id", id);
				 try{
					 cmd->ExecuteNonQuery();
				 }
				 catch (Exception^ ex){
					 mostrarError("Error: "+ex->Message);
					 delete ex;
				 }
				 finally{
					mysql_conn->Close();
				 }
			 }
}

private: System::Void btn_cancelar_venta_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->dtgv_realizar_venta->Rows->Clear();
}
private: System::Void btn_eliminar_producto_comp_Click(System::Object^  sender, System::EventArgs^  e) {
			 DataGridViewSelectedRowCollection^ rows = this->dtgv_productos->SelectedRows;
			 if (rows->Count)
			 {
				 Windows::Forms::DialogResult conf = MessageBox::Show("¿Seguro que quiere borrar esos registros?", "Confirmacion",
					 MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				 if (conf == Windows::Forms::DialogResult::Yes){
					 for each (DataGridViewRow^ row in rows)
					 {
						 this->dtgv_realizar_venta->Rows->RemoveAt(row->Index);
					 }
					 //refrescarTablaProductos();
				 }
			 }
}
private: System::Void btn_terminar_compra_Click(System::Object^  sender, System::EventArgs^  e) {
	DataGridViewRowCollection^ rows = this->dtgv_realizar_venta->Rows;
	int id_venta = 0;
	if (rows->Count)
	{
		//primero crear la venta
		Nota^ nota = gcnew Nota();
		Windows::Forms::DialogResult conf = nota->ShowDialog(this);
		//mostrarError();/
		
		if (conf == Windows::Forms::DialogResult::OK){
			/*registrar la venta*/
			mysql_conn->Open();
			MySqlCommand^ cmd = mysql_conn->CreateCommand();
			cmd->CommandText = L"INSERT INTO ventas VALUES(NULL,NOW(),@nota);SELECT @@identity;";
			cmd->Parameters->AddWithValue("@nota", nota->txt_nota->Text);
			MySqlDataReader^ ultimo_id = cmd->ExecuteReader();
			if (ultimo_id->Read()){
				id_venta = ultimo_id->GetInt32(0);
			}
			cmd->Parameters->Clear();
			mysql_conn->Close();
			/*agregar cada venta de producto a la tabla venta con sus respectivos valores*/
			for each (DataGridViewRow^ row in rows)
			{
				/*primero obtener el id del producto vendido*/
				mysql_conn->Open();
				cmd->CommandText = L"SELECT id,precio FROM productos WHERE nombre=@nombre_prod";
				cmd->Parameters->AddWithValue("@nombre_prod", row->Cells[1]->Value->ToString());
				MySqlDataReader^ res = cmd->ExecuteReader();
				if (res->Read())/*si existe el producto que se vende*/
				{
					int id_producto = res->GetInt32(0);
					float precio = res->GetFloat(1);
					mysql_conn->Close();
					mysql_conn->Open();
					cmd->CommandText = L"INSERT INTO venta VALUES(NULL,@id_ventas,@id_producto,@cantidad,@precio)";
					cmd->Parameters->Clear();
					cmd->Parameters->AddWithValue("@id_ventas", id_venta);
					cmd->Parameters->AddWithValue("@id_producto", id_producto);
					cmd->Parameters->AddWithValue("@cantidad", row->Cells[2]);
					cmd->Parameters->AddWithValue("@precio", precio);
					cmd->ExecuteNonQuery();
				}
				mysql_conn->Close();
			}
		}
		delete nota;
	}
	else{
		mostrarError("Agregue al menos un producto para relizar una venta!");
	}
	//crear el pdf
	try{
		Document^ doc = gcnew Document(PageSize::LETTER);
		PdfWriter^ writer = PdfWriter::GetInstance(doc, File::Create("e:\\reporte.pdf"));/*NO tiene ese disco?? ni modo... me dio fojera solucionarlo!*/
		doc->AddTitle("Recibo");
		doc->AddAuthor("Electronica XXI");
		doc->AddCreationDate();
		doc->Open();
		iTextSharp::text::Font^ fuente_titulo = gcnew iTextSharp::text::Font(iTextSharp::text::Font::FontFamily::HELVETICA, 11, 2, BaseColor::BLACK);
		iTextSharp::text::Font^ fuente = gcnew iTextSharp::text::Font(iTextSharp::text::Font::FontFamily::HELVETICA, 9, 0, BaseColor::BLACK);
		doc->Add(gcnew Paragraph("Recibo NO. "+id_venta));
		doc->Add(Chunk::NEWLINE);
		PdfPTable^ tbl = gcnew PdfPTable(5);
		tbl->WidthPercentage = 100;

		// Configuramos el título de las columnas de la tabla
		PdfPCell^ numero = gcnew PdfPCell(gcnew Phrase("Numero", fuente_titulo));
		numero->BorderWidth = 0;
		numero->BorderWidthBottom = 0.75f;

		PdfPCell^ nombre = gcnew PdfPCell(gcnew Phrase("Nombre", fuente_titulo));
		nombre->BorderWidth = 0;
		nombre->BorderWidthBottom = 0.75f;

		PdfPCell^ cantidad = gcnew PdfPCell(gcnew Phrase("cantidad", fuente_titulo));
		cantidad->BorderWidth = 0;
		cantidad->BorderWidthBottom = 0.75f;

		PdfPCell^ precio = gcnew PdfPCell(gcnew Phrase("precio", fuente_titulo));
		precio->BorderWidth = 0;
		precio->BorderWidthBottom = 0.75f;

		PdfPCell^ total = gcnew PdfPCell(gcnew Phrase("total", fuente_titulo));
		total->BorderWidth = 0;
		total->BorderWidthBottom = 0.75f;

		// Añadimos las celdas a la tabla
		tbl->AddCell(numero);
		tbl->AddCell(nombre);
		tbl->AddCell(cantidad);
		tbl->AddCell(precio);
		tbl->AddCell(total);

		// Llenamos la tabla con información
		DataGridViewRowCollection^ renglones = this->dtgv_realizar_venta->Rows;
		float total_venta_sing = 0, total_venta=0;
		for each (DataGridViewRow^ row in renglones)
		{
			//row->Cells[]
			numero = gcnew PdfPCell(gcnew Phrase(row->Cells[0]->Value->ToString(), fuente));
			numero->BorderWidth = 0;

			nombre = gcnew PdfPCell(gcnew Phrase(row->Cells[1]->Value->ToString(), fuente));
			nombre->BorderWidth = 0;

			cantidad = gcnew PdfPCell(gcnew Phrase(row->Cells[2]->Value->ToString(), fuente));
			cantidad->BorderWidth = 0;

			precio = gcnew PdfPCell(gcnew Phrase(row->Cells[3]->Value->ToString(), fuente));
			precio->BorderWidth = 0;

			total_venta_sing = float::Parse(row->Cells[2]->Value->ToString())*float::Parse(row->Cells[3]->Value->ToString());
			total_venta += total_venta_sing;
			total = gcnew PdfPCell(gcnew Phrase("" + total_venta_sing, fuente));
			total->BorderWidth = 0;

			tbl->AddCell(numero);
			tbl->AddCell(nombre);
			tbl->AddCell(cantidad);
			tbl->AddCell(precio);
			tbl->AddCell(total);
		}
		doc->Add(Chunk::NEWLINE);

		numero = gcnew PdfPCell(gcnew Phrase("", fuente));
		numero->BorderWidth = 0;
		tbl->AddCell(numero);

		nombre = gcnew PdfPCell(gcnew Phrase("", fuente));
		nombre->BorderWidth = 0;
		tbl->AddCell(nombre);

		cantidad = gcnew PdfPCell(gcnew Phrase("", fuente));
		cantidad->BorderWidth = 0;
		tbl->AddCell(cantidad);

		precio = gcnew PdfPCell(gcnew Phrase("total", fuente_titulo));
		precio->BorderWidth = 0;
		tbl->AddCell(precio);

		total = gcnew PdfPCell(gcnew Phrase("" + total_venta, fuente_titulo));
		total->BorderWidth = 0;
		tbl->AddCell(total);

		doc->Add(tbl);

		doc->Close();
		writer->Close();

		mostrarCompraPDF();
	}
	catch (Exception^ex){
		mostrarError(ex->Message);
	}
}
private: System::Void btn_buscar_ventas_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ventas_filtro_busqueda = "WHERE CONCAT(id,' ',fecha,' ',nota) like '%"
				 + this->txt_buscar_ventas->Text + "%' ";
			 refrescarTablaVentas();
}
private: System::Void cbx_filtro_ventas_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 ArrayList ^items = gcnew ArrayList();
			 items->Add("id");
			 items->Add("fecha");
			 items->Add("nota");
			 this->provedores_orderby = "ORDER BY " + items[this->cbx_filtro_ventas->SelectedIndex];
			 refrescarTablaVentas();
}
private: System::Void txt_buscar_ventas_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_buscar_ventas_Click(nullptr, EventArgs::Empty);
			 }
}


private: System::Void btn_navegar_atras_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_misc->GoBack();
}	
private: System::Void btn_navegar_adelante_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_misc->GoForward();
}
private: System::Void btn_navegar_ir_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_misc->Navigate(this->txt_navegar->Text );
}
private: System::Void txt_navegar_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
			 {
				 btn_navegar_ir_Click(nullptr, EventArgs::Empty);
			 }
}

private: System::Void btn_recargar_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wb_misc->Refresh();
}
private: System::Void btn_cargar_video_Click(System::Object^  sender, System::EventArgs^  e) {
			Windows::Forms::DialogResult res = this->fd_abrir_archivos_player->ShowDialog();
			if (res == Windows::Forms::DialogResult::OK)
			{
				array<String^> ^files =this->fd_abrir_archivos_player->FileNames;
				for each (String^ file in files)
				{
					this->wmp_media_player->currentPlaylist->appendItem(this->wmp_media_player->newMedia(file));
					this->lstbx_videos->Items->Add(file);
				}
				btn_play_pause_Click(nullptr, EventArgs::Empty);
			}		
}
/*private: System::Void btn_lista_reproduccion_Click(System::Object^  sender, System::EventArgs^  e) {
			 ListaReproduccion ^lista=gcnew ListaReproduccion();
			 IWMPPlaylist^ playlist = this->wmp_media_player->currentPlaylist;
			 for (size_t i = 0; i < playlist->count; i++)
			 {
				 lista->lstv_videos->Items->Add(playlist->Item[i]->sourceURL);
			 }
			 Windows::Forms::DialogResult res = lista->ShowDialog();
			 
}*/
private: System::Void btn_full_screen_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 this->wmp_media_player->fullScreen = true;
			 }
			 catch (Exception^ ex){ }
}

void mostrarCompraPDF(){
	Reporte^r = gcnew Reporte();
	r->ShowDialog();

}

private: System::Void tb_volumen_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 this->wmp_media_player->settings->volume = this->tb_volumen->Value;
			 this->lbl_volumen->Text = "volumen " + this->wmp_media_player->settings->volume;
			 this->mudo = false;
			 this->btn_mudo->Image = System::Drawing::Image::FromFile("img\\sound_low.png");
}
private: System::Void btn_play_pause_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->pausa){
				 this->wmp_media_player->Ctlcontrols->pause();
				 this->btn_play_pause->Image = System::Drawing::Image::FromFile("img\\control_play_blue.png");
				 this->pausa = false;
			 }
			 else{
				 this->wmp_media_player->Ctlcontrols->play();
				 this->btn_play_pause->Image = System::Drawing::Image::FromFile("img\\control_pause_blue.png");
				 this->pausa = true;
			 }
}
private: System::Void btn_stop_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wmp_media_player->Ctlcontrols->stop();
			 this->btn_play_pause->Image = System::Drawing::Image::FromFile("img\\control_play_blue.png");
			 this->pausa = false;
}
private: System::Void btn_adelante_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wmp_media_player->Ctlcontrols->next();
}
private: System::Void btn_atras_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wmp_media_player->Ctlcontrols->previous();
}
private: System::Void wb_misc_Navigated(System::Object^  sender, System::Windows::Forms::WebBrowserNavigatedEventArgs^  e) {
			 this->txt_navegar->Text = this->wb_misc->Url->ToString();
}
private: System::Void btn_mudo_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->mudo)
			 {
				 this->mudo = false;
				 this->btn_mudo->Image = System::Drawing::Image::FromFile("img\\sound_low.png");
			 }
			 else{
				 this->mudo = true;
				 this->btn_mudo->Image = System::Drawing::Image::FromFile("img\\sound_mute.png");
			 }
			 this->wmp_media_player->settings->mute = this->mudo;
}
private: System::Void lstbx_videos_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 this->wmp_media_player->Ctlcontrols->playItem(this->wmp_media_player->currentPlaylist->Item[this->lstbx_videos->SelectedIndex]);
				 //this->wmp_media_player->currentMedia = 
				 btn_play_pause_Click(nullptr, EventArgs::Empty);
			 }
			 catch (Exception^ e){ }
}
private: System::Void btn_limpiar_lista_rep_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->wmp_media_player->currentPlaylist->clear();
			 this->lstbx_videos->Items->Clear();
}
private: System::Void acercaDeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Acerca", "Este sistema fué creado para manejar \nlos productos y ventas de una tienda de electrónica.", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};


}

