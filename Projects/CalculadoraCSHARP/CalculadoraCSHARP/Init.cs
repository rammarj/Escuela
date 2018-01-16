using System;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
namespace calculadora2
{

	using funcionalidad;
	/// 
	/// <summary>
	/// @author Joaquin R. Martinez
	/// </summary>
	public class Init
	{
		public static void Main(string[] args)
		{
			Calculadora calc = new Suma(4,4);
			Console.WriteLine(calc.calcular());
            Console.Read();
		}
	}

}