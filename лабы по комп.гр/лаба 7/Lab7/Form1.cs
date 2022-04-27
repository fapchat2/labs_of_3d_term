using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Lab7.Properties;

namespace Lab7
{
    public partial class Form1 : Form
    {

        Bitmap pictureBoxBitMap;

        Bitmap spriteBitMap;

        Bitmap cloneBitMap;

        Graphics g_pictureBox;

        Graphics g_sprite;

        Graphics g;
        int x, y; // Координаты ракеты
        int width = 630, height = 340; // Ширина и высота, поглощающая ракету в её начальном положении
        Timer timer;
        public Form1()
        {
            InitializeComponent();

            
            // Создаём Bitmap для pictureBox1 и графический контекст
            Image Background = Resources.Background;
            
            pictureBox1.Image = Background;
            pictureBoxBitMap = new Bitmap(pictureBox1.Image);
            g_pictureBox = Graphics.FromImage(pictureBox1.Image);
            // Создаём Bitmap для спрайта и графический контекст
            spriteBitMap = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            g_sprite = Graphics.FromImage(spriteBitMap); //g_sprite рисуется не сразу + объект, нарисованный с его помощью, движется!

            // Рисуем ракету на графическом контексте g_sprite
            DrawSprite();
            // Создаём Bitmap для временного хранения части изображения
            cloneBitMap = new Bitmap(width, height);
            // Задаем начальные координаты вывода движущегося объекта
            x = 0; y = 0;
            // Сохраняем область экрана перед первым выводом объекта
            SavePart(x, y);
            // Перерисовываем pictureBox1
            pictureBox1.Invalidate();
            // Создаём таймер с интервалом 100 миллисекунд
            timer = new Timer();
            timer.Interval = 60;
            timer.Tick += new EventHandler(timer1_Tick);
            
        }

        void DrawSprite()
        {
            SolidBrush rocket = new SolidBrush(Color.FromArgb(22, 15, 15));
            //Rocket:
            Point[] pointsOfRocket = new Point[7] { new Point(560, 240), new Point(610, 240), new Point(630, 260), new Point(610, 280), new Point(560, 280), new Point(570, 260), new Point(560, 240) };
            g_sprite.FillPolygon(rocket, pointsOfRocket);
        }
    
        void SavePart(int xt, int yt)
        {
            Rectangle cloneRect = new Rectangle(xt, yt, width, height);
            System.Drawing.Imaging.PixelFormat format = pictureBoxBitMap.PixelFormat;
            cloneBitMap = pictureBoxBitMap.Clone(cloneRect, format);
        }
        private void Form1_Load(object sender, EventArgs e)
        {
           
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            //ship
            SolidBrush ship = new SolidBrush(Color.FromArgb(50, 50, 55));
            SolidBrush window = new SolidBrush(Color.FromArgb(150, 150, 195));

            Point[] pointsOfShip = new Point[7] { new Point(0, 260), new Point(80, 320), new Point(400, 320), new Point(480, 320), new Point(560, 260), new Point(480, 200), new Point(80, 200) };
            //GraphicsPath myGraphicsPath = new GraphicsPath();
            e.Graphics.FillPolygon(ship, pointsOfShip);

            e.Graphics.FillEllipse(window, 420, 220, 40, 40);
            e.Graphics.FillEllipse(window, 320, 220, 40, 40);
            e.Graphics.FillEllipse(window, 220, 220, 40, 40);
            e.Graphics.FillEllipse(window, 120, 220, 40, 40);
            SolidBrush water = new SolidBrush(Color.FromArgb(51, 51, 255));
            SolidBrush sun = new SolidBrush(Color.Yellow);
            e.Graphics.FillRectangle(water, 0, pictureBox1.Height - 60, pictureBox1.Width - 1, 60);
            e.Graphics.FillEllipse(sun, 0, 0, 100, 100);

        }

        private void timer1_Tick(object sender, EventArgs e)
        {


            g_pictureBox.DrawImage(cloneBitMap, x, 0);

            x += 6;

            if (x > pictureBox1.Width - 1) x = pictureBox1.Location.X; /// после выхода ракеты за рамки pictureBox без этого может произойти ошибка System.OutOfMemoryException: "Недостаточно памяти.", хотя на полёт ракеты не влияет

            SavePart(x, y);

            g_pictureBox.DrawImage(spriteBitMap, x, 0);

            pictureBox1.Invalidate();
        }
        // Включаем таймер по нажатию на кнопку
        private void button1_Click(object sender, EventArgs e)
        {
            timer.Enabled = true;
        }

        

    }
}
