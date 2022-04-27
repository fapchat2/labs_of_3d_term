//Задание:
//Создать перечисленные ниже изображения(при рисовании использовать
//весь набор методов построения графических примитивов).

//4.Легковой автомобиль, совершающий обгон грузового автомобиля.
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            
            SolidBrush tire = new SolidBrush(Color.Black);
            SolidBrush car = new SolidBrush(Color.Yellow);
            SolidBrush truck = new SolidBrush(Color.Orange);
            SolidBrush truckTop = new SolidBrush(Color.Red);


            // ******* 1 - Рисуем машину ************
            // Рисуем два прямоугольника
            g.FillRectangle(car, 460, 115, 60, 30);
            g.FillRectangle(car, 395, 145, 200, 50);

            g.FillEllipse(tire, 420, 175, 40, 40);
            g.FillEllipse(tire, 530, 175, 40, 40);

            // ******* 2 - Рисуем грузовик ************
            g.FillRectangle(truck, 50, 175, 200, 100);
            g.FillRectangle(truckTop, 250, 155, 90, 120);

            g.FillEllipse(tire, 80, 255, 40, 40);
            g.FillEllipse(tire, 190, 255, 40, 40);

            Pen blackPen = new Pen(Color.Black, 3);

            // Create points that define polygon.
            PointF point1 = new PointF(50.0F, 200.0F);
            PointF point2 = new PointF(100.0F, 180.0F);
            PointF point3 = new PointF(100.0F, 150.0F);
            PointF point4 = new PointF(50.0F, 170.0F);

            PointF[] curvePoints =
                     {
                 point1,
                 point2,
                 point3,
                 point4
             };

            // Draw polygon curve to screen.
            g.DrawPolygon(blackPen, curvePoints);

             point1 = new PointF(100.0F, 180.0F);
             point2 = new PointF(247.0F, 180.0F);
             point3 = new PointF(247.0F, 150.0F);
             point4 = new PointF(100.0F, 150.0F);
            PointF[] curvePoints1 =
                     {
                 point1,
                 point2,
                 point3,
                 point4
             };

            g.DrawPolygon(blackPen, curvePoints1);

            // Create rectangle to bound ellipse.
            Rectangle rect = new Rectangle(475, 157, 10, 5);

            // Create start and sweep angles on ellipse.
            float startAngle = 45.0F;
            float sweepAngle = 270.0F;

            // Draw arc to screen.
            e.Graphics.DrawArc(blackPen, rect, startAngle, sweepAngle);



            rect = new Rectangle(260, 230, 10, 5);

            // Create start and sweep angles on ellipse.
            startAngle = 45.0F;
            sweepAngle = 270.0F;

            // Draw arc to screen.
            e.Graphics.DrawArc(blackPen, rect, startAngle, sweepAngle);


            rect = new Rectangle(580, 150, 10, 25);

            // Draw ellipse to screen.
            e.Graphics.DrawEllipse(blackPen, rect);


            SolidBrush blackBrush = new SolidBrush(Color.Black);


            rect = new Rectangle(52, 200, 10, 60);

            // Fill ellipse on screen.
            e.Graphics.FillEllipse(blackBrush, rect);

            rect = new Rectangle(400, 150, 10, 28);

            // Fill ellipse on screen.
            e.Graphics.FillEllipse(blackBrush, rect);


            // Create points that define line.
            point1 = new PointF(253.0F, 160.0F);
            point2 = new PointF(253.0F, 190.0F);

            // Draw line to screen.
            e.Graphics.DrawLine(blackPen, point1, point2);


            point1 = new PointF(253.0F, 190.0F);
            point2 = new PointF(340.0F, 190.0F);

            // Draw line to screen.
            e.Graphics.DrawLine(blackPen, point1, point2);



            point1 = new PointF(251.0F, 175.0F);
            point2 = new PointF(251.0F, 275.0F);

            // Draw line to screen.
            e.Graphics.DrawLine(blackPen, point1, point2);

        }
    }
}
