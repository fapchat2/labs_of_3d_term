//Разместить на форме компонент PictureBox, три кнопки для вывода
//графика по стандартам страничного пространства Pixel, Millimeter, Inch и
//кнопку очистки компонента PictureBox.
//Выбрать самостоятельно математический интервал по оси Х, на котором
//будет строиться график функции. Например, для функции Sin(x) взять интервал
//от -2π до 2π.
//Центр координат должен находиться в центре PictureBox.
//При нажатии на кнопки, используя метод DrawLine нарисовать
//обрамляющую рамку для PictureBox и координатные оси. Цвет рамки и осей
//установить в один из именованных цветов.
//Свойство BackColor для PictureBox устанавить методами
//Color.FromKnownColor и Color.FromName, например,
//Color.FromKnownColor(KnownColor.ControlLightLight) и Color.FromName("Info") в
//один из системных цветов.
//По нажатию на каждую из трёх кнопок вывести график функции,
//указанной в варианте задания, используя соответствующий стандарт
//страничного пространства: Pixel, Millimeter и Inch. Цвет графика задаёт

//2

//пользователь, используя метод Color.FromArgb, например,
//Color.FromArgb(210,224,200).
//Очистку объекта Graphics методом Clear выполнить цветом, созданным
//пользователем.
//Пример вывода графика функции Sin(X) показан на рисунке 2.7.


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        //Пикселей в одном делении оси
        const int PIX_IN_ONE = 15;
        //Длина стрелки
        const int ARR_LEN = 10;

        public Form1()
        {
            InitializeComponent();
            pictureBox1.BackColor = Color.FromKnownColor(KnownColor.ControlLightLight);

        }

        private void DrawXAxis(Point start, Point end, Graphics g)
        {
            g.DrawLine(Pens.Black, start, end);
        }

        //Рисование оси Y
        private void DrawYAxis(Point start, Point end, Graphics g)
        {
            g.DrawLine(Pens.Black, start, end);
        }

        public static DialogResult InputBox(string title, string promptText, ref string value)
        {
            Form form = new Form();
            Label label = new Label();
            TextBox textBox = new TextBox();
            Button buttonOk = new Button();
            Button buttonCancel = new Button();

            form.Text = title;
            label.Text = promptText;
            textBox.Text = value;

            buttonOk.Text = "OK";
            buttonCancel.Text = "Cancel";
            buttonOk.DialogResult = DialogResult.OK;
            buttonCancel.DialogResult = DialogResult.Cancel;

            label.SetBounds(9, 20, 372, 13);
            textBox.SetBounds(12, 36, 372, 20);
            buttonOk.SetBounds(228, 72, 75, 23);
            buttonCancel.SetBounds(309, 72, 75, 23);

            label.AutoSize = true;
            textBox.Anchor = textBox.Anchor | AnchorStyles.Right;
            buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
            buttonCancel.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;

            form.ClientSize = new Size(396, 107);
            form.Controls.AddRange(new Control[] { label, textBox, buttonOk, buttonCancel });
            form.ClientSize = new Size(Math.Max(300, label.Right + 10), form.ClientSize.Height);
            form.FormBorderStyle = FormBorderStyle.FixedDialog;
            form.StartPosition = FormStartPosition.CenterScreen;
            form.MinimizeBox = false;
            form.MaximizeBox = false;
            form.AcceptButton = buttonOk;
            form.CancelButton = buttonCancel;

            DialogResult dialogResult = form.ShowDialog();
            value = textBox.Text;
            return dialogResult;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            string value = "111";
            int color0 = 0, color1 = 0, color2 = 0;
            if (InputBox("Color.FromArgb", "Color.FromArgb 1rst value(red):", ref value) == DialogResult.OK)
            {
                color0 = Convert.ToInt32(value);
            }

            if (InputBox("Color.FromArgb", "Color.FromArgb 2nd value(green):", ref value) == DialogResult.OK)
            {
                color1 = Convert.ToInt32(value);
            }

            if (InputBox("Color.FromArgb", "Color.FromArgb 3rd value(blue):", ref value) == DialogResult.OK)
            {
                color2 = Convert.ToInt32(value);
            }
            Color col = Color.FromArgb(color0, color1, color2);
            pictureBox1.BackColor = col;

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {


        }

        private void button1_Click(object sender, EventArgs e)
        {
            int w = pictureBox1.ClientSize.Width / 2;
            int h = pictureBox1.ClientSize.Height / 2;
            Graphics gr = pictureBox1.CreateGraphics();
            Pen pen = new Pen(Color.Black, 2f);

            PointF point1 = new PointF(0, 0);
            PointF point2 = new PointF(2 * w, 0);
            gr.DrawLine(pen, point1, point2);

            point1 = new PointF(2 * w, 0);
            point2 = new PointF(2 * w, 2 * h);
            gr.DrawLine(pen, point1, point2);

            point1 = new PointF(2 * w, 2 * h);
            point2 = new PointF(0, 2 * h);
            gr.DrawLine(pen, point1, point2);

            point1 = new PointF(0, 2 * h);
            point2 = new PointF(0, 0);
            gr.DrawLine(pen, point1, point2);

            gr.TranslateTransform(w, h);
            DrawXAxis(new Point(-w, 0), new Point(w, 0), gr);
            DrawYAxis(new Point(0, h), new Point(0, -h), gr);

            string value = "111";
            int color0 = 0, color1 = 0, color2 = 0;
            if (InputBox("Color.FromArgb", "Color.FromArgb 1rst value(red):", ref value) == DialogResult.OK)
            {
                color0 = Convert.ToInt32(value);
            }

            if (InputBox("Color.FromArgb", "Color.FromArgb 2nd value(green):", ref value) == DialogResult.OK)
            {
                color1 = Convert.ToInt32(value);
            }

            if (InputBox("Color.FromArgb", "Color.FromArgb 3rd value(blue):", ref value) == DialogResult.OK)
            {
                color2 = Convert.ToInt32(value);
            }
            Color col = Color.FromArgb(color0, color1, color2);
            pen = new Pen(col, 2f);
            for (int i = 0; i < w; i++)
            {
                point1 = new PointF(i, (int)(Math.Sin((double)i / 10) * 100));
                point2 = new PointF((i + 1), (int)(Math.Sin((double)(i + 1) / 10) * 100));
                gr.DrawLine(pen, point1, point2);


            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            int w = Convert.ToInt16(pictureBox1.Size.Width / 2 / 3.799999999);
            int h = Convert.ToInt16(pictureBox1.Size.Height / 2 / 3.799999999);

            Graphics gr = pictureBox1.CreateGraphics();

            gr.PageUnit = GraphicsUnit.Millimeter;

            Pen pen = new Pen(Color.Black, 1f);

            PointF point1 = new PointF(0, 0);
            PointF point2 = new PointF(2 * w, 0);
            gr.DrawLine(pen, point1, point2);

            point1 = new PointF(2 * w, 0);
            point2 = new PointF(2 * w, 2 * h);
            gr.DrawLine(pen, point1, point2);

            point1 = new PointF(2 * w, 2 * h);
            point2 = new PointF(0, 2 * h);
            gr.DrawLine(pen, point1, point2);

            point1 = new PointF(0, 2 * h);
            point2 = new PointF(0, 0);
            gr.DrawLine(pen, point1, point2);

            gr.TranslateTransform(w, h);

            DrawXAxis(new Point(-w, 0), new Point(w, 0), gr);
            DrawYAxis(new Point(0, h), new Point(0, -h), gr);

            string value = "111";
            int color0 = 0, color1 = 0, color2 = 0;
            if (InputBox("Color.FromArgb", "Color.FromArgb 1rst value(red):", ref value) == DialogResult.OK)
            {
                color0 = Convert.ToInt32(value);
            }

            if (InputBox("Color.FromArgb", "Color.FromArgb 2nd value(green):", ref value) == DialogResult.OK)
            {
                color1 = Convert.ToInt32(value);
            }

            if (InputBox("Color.FromArgb", "Color.FromArgb 3rd value(blue):", ref value) == DialogResult.OK)
            {
                color2 = Convert.ToInt32(value);
            }
            Color col = Color.FromArgb(color0, color1, color2);
            pen = new Pen(col, 1f);
            for (int i = 0; i < w; i++)
            {
                point1 = new PointF(i , (int)(Math.Sin((double)i / 10) * 30));
                point2 = new PointF((i + 1) , (int)(Math.Sin((double)(i + 1) / 10) * 30));
                gr.DrawLine(pen, point1, point2);


            }

        }

  
    }
}
