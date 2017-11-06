using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SerialPortListener
{
    public partial class switch_on_off : Form
    {
        public switch_on_off()
        {
            InitializeComponent();
            serialPort1.Open();
        }

        private void switch_on_off_Load(object sender, EventArgs e)
        {
   
        }

        private void imageSlider1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("A");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Write("J");
        }
    }
}