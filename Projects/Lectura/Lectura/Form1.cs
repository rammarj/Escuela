using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Speech.Synthesis;

namespace Lectura
{
    public partial class Form1 : Form
    {
        SpeechSynthesizer tts;
        public Form1()
        {
            InitializeComponent();
            this.tts = new SpeechSynthesizer();
            //Microsoft Sabina Desktop
            //Microsoft Zira Desktop
            //
            IReadOnlyCollection<InstalledVoice> a = tts.GetInstalledVoices();
            foreach (InstalledVoice i in a)
            {
                Console.WriteLine(i.VoiceInfo.Name);
            }
            this.tts.SelectVoice("Microsoft Zira Desktop");
        }

        private void btnLeer_Click(object sender, EventArgs e)
        {
            this.tts.Speak(this.txtTexto.Text);
        }

        private void btnPausar_Click(object sender, EventArgs e)
        {
            this.tts.Pause();
        }

        private void Continuar_Click(object sender, EventArgs e)
        {
            this.tts.Resume();
        }

    }
}
