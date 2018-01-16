/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
namespace calculadora2.funcionalidad
{

	/// 
	/// <summary>
	/// @author Joaquin R. Martinez
	/// </summary>
	public class Multiplicacion : Calculadora
	{

		internal float val1, val2;

		public Multiplicacion()
		{
		}

		public Multiplicacion(float val1, float val2)
		{
			this.val1 = val1;
			this.val2 = val2;
		}

		public override float calcular()
		{
			return val1 / val2;
		}

		public override float calcular(float val1, float val2)
		{
			return val1 / val2;
		}

	}

}