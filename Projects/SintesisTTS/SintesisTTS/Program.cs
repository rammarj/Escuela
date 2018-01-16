using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Speech.Synthesis;
using System.Collections.ObjectModel;

namespace SintesisTTS
{
    class Program
    {
        static void Main(string[] args)
        {

            SpeechSynthesizer tts = new SpeechSynthesizer();
            ReadOnlyCollection<InstalledVoice>b = tts.GetInstalledVoices();
            
            tts.Speak("Empezaste a utilizar SpeechSynthesizer ahora mismo");
            Console.Read();
        }
    }
}
