//Во всех вариантах заданий подобрать размер символов таким образом,
//чтобы все строки помещались в объекте Graphics и не перекрывали друг друга.
//Написать программу, которая создавала бы на диске текстовый файл и
//записывала в него указанное количество строк. Открывала существующий
//файл, считывала строки и выводила три группы строк с указанными в варианте
//номерами строк каждой группы, шрифтами, стилем, размером, направлением
//вывода и выравниванием. Пример вывода показан на рисунке 3.5.

//Вариант 4
//1–8
//9–10
//11

//Magneto
//Perpetua
//Cambria

//Bold
//Italic
//Regular
//18
//24
//2 inch
//Горизонтально
//Вертикально
//Горизонтально

//Center, Far
//Near, Far
//Center, Near
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Graphics g;
        string filename = @"Strings.txt";
        string[] sm = {

"First line", "Second line", "Third line",
"Fourth line", "Fifth line", "Sixth line",
"Seventh line", "Eighth line", "Ninth line",
"Tenth line", "Eleven line"};
        public Form1()
        {
            InitializeComponent();
            // Предоставляем объекту "g" класса Graphics возможность
            // рисования на pictureBox1:
            g = pictureBox1.CreateGraphics();
        }
        // **************** Запись в файл ********************
        private void InFile_Click(object sender, EventArgs e)
        {
            StreamWriter f = new StreamWriter(new FileStream(filename,
            FileMode.Create, FileAccess.Write));

            foreach (string s in sm) { f.WriteLine(s); }
            f.Close();
            MessageBox.Show("11 строк записано в файл !");
        }
        // *************** Очистка файла и PictureBox **********
        private void ClearFile_Click(object sender, EventArgs e)
        {
            g.Clear(Color.FromArgb(255, 255, 255));
            File.Delete(filename);
            MessageBox.Show("Файл Strings.txt удалён !");
        }


        // *************** Отображение строк текста *************
        private void ShowText_Click(object sender, EventArgs e)
        {
            int k = 0;
            // Чтение строк из файла
            try
            {
                StreamReader f = new StreamReader(new FileStream(filename,
                FileMode.Open, FileAccess.Read));
                for (int i = 0; i < 11; i++) { sm[i] = f.ReadLine(); }
                f.Close();
            }
            catch (Exception ex) { MessageBox.Show(ex.Message); }
            // **** Отображение строк разными шрифтами и выравниванием **
            pictureBox1.BackColor = Color.FromName("Azure");
            pictureBox1.Refresh();
            for (int i = 0; i < 11; i++)
            {
                // Отображение первой группы строк
                if ((i >= 0) && (i < 8))
                {
                    Font fn = new Font("Magneto", 18, FontStyle.Bold);
                    StringFormat sf =
                    (StringFormat)StringFormat.GenericTypographic.Clone();
                    sf.Alignment = StringAlignment.Center;
                    sf.LineAlignment = StringAlignment.Far;
                    g.DrawString(sm[i], fn, Brushes.Blue,
                    new RectangleF(0, -400 + i * 30, pictureBox1.Size.Width - 20,
                    pictureBox1.Size.Height - 20), sf);
                    fn.Dispose();
                }
                // Отображение второй группы строк
                if (i == 8 || i == 9)
                {
                    k = i - 9;
                    Font fn = new Font("Perpetua", 24, FontStyle.Italic);
                    StringFormat sf =
                    (StringFormat)StringFormat.GenericTypographic.Clone();
                    sf.FormatFlags = StringFormatFlags.DirectionVertical;
                    sf.Alignment = StringAlignment.Near;
                    sf.LineAlignment = StringAlignment.Far;
                    g.DrawString(sm[i], fn, Brushes.Black,
                    new RectangleF(0 + k * 24, 0, pictureBox1.Size.Width - 20,
                    pictureBox1.Size.Height - 20), sf);
                    fn.Dispose();
                }
                // Отображение третьей группы строк
                if (i == 10)
                {
                    Font fn = new Font("Cambria", 2f, FontStyle.Regular, GraphicsUnit.Inch);
                    StringFormat sf =
                    (StringFormat)StringFormat.GenericTypographic.Clone();
                    sf.Alignment = StringAlignment.Center;
                    sf.LineAlignment = StringAlignment.Near;
                    g.DrawString(sm[i], fn, Brushes.Green,
                    new RectangleF(0, 0 + i * 29, pictureBox1.Size.Width - 20,
                    pictureBox1.Size.Height - 20), sf);
                    fn.Dispose();
                    g.PageUnit = GraphicsUnit.Pixel;

                }

            }
        }

            private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            InFile_Click(sender, e);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ShowText_Click(sender, e);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ClearFile_Click(sender, e);
        }
    }
}
