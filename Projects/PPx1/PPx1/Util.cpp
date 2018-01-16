#include "Util.h"
/*muestra error*/
void Util::mostrarError(String^ error){
	MessageBox::Show(error, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
/*Rellena lo datos en un datagrid*/
void Util::rellenarDatagrid(DataGridView^ dt, ArrayList^ cols, MySqlDataReader^ res){
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