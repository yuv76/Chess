using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace chessGraphics
{
    public partial class Form1 : Form
    {
        private bool gameStarted = false;
        private bool isMer = false;
        private Square srcSquare;
        private Square dstSquare;

        private pipe enginePipe;
        Button[,] matBoard;

        bool isCurPlWhite = true;
        bool isGameOver = false;

        const int BOARD_SIZE = 8;

        public Form1()
        {
            InitializeComponent();
        }

        private void initForm()
        {
            enginePipe.connect();

            Invoke((MethodInvoker)delegate {  

                lblWaiting.Visible = false;
                lblCurrentPlayer.Visible = true;
                label1.Visible = true;

                        

                string s = enginePipe.getEngineMessage();

                if (s.Length != (BOARD_SIZE * BOARD_SIZE + 1))
                {
                    MessageBox.Show("The length of the board's string is not according the PROTOCOL");
                    this.Close();

                }
                else
                {
                    isCurPlWhite = (s[s.Length - 1] == '0');
                    gameStarted = true;
                    paintBoard(s);
                }

            });
    
        }

        Thread connectionThread;
        private void Form1_Load(object sender, EventArgs e)
        {
            enginePipe = new pipe();
            //this.Show();
            
            //MessageBox.Show("Press OK to start waiting for engine to connect...");
            connectionThread = new Thread(initForm);
            connectionThread.Start();
            connectionThread.IsBackground = true;
            
            //initForm();
        
        }

        Image getImageBySign(char sign)
        {
            switch (sign)
            {
                case 'q':
                    return Properties.Resources.q_black;
                case 'Q':
                    return Properties.Resources.q_white;
                case 'k':
                    return Properties.Resources.k_black;
                case 'K':
                    return Properties.Resources.k_white;
                case 'p':
                    return Properties.Resources.p_black;
                case 'P':
                    return Properties.Resources.p_white;
                case 'r':
                    return Properties.Resources.r_black;
                case 'R':
                    return Properties.Resources.r_white;
                case 'n':
                    return Properties.Resources.n_black;
                case 'N':
                    return Properties.Resources.n_white;
                case 'b':
                    return Properties.Resources.b_black;
                case 'B':
                    return Properties.Resources.b_white;
                case '#':
                    return null;
                default:
                    return Properties.Resources.x;

            }
        }

        Image getMerImageBySign(char sign)
        {
            switch (sign)
            {
                case 'q':
                    return Properties.Resources.q_black_mer;
                case 'Q':
                    return Properties.Resources.q_white_mer;
                case 'k':
                    return Properties.Resources.k_black_mer;
                case 'K':
                    return Properties.Resources.k_white_mer;
                case 'p':
                    return Properties.Resources.p_black_mer;
                case 'P':
                    return Properties.Resources.p_white_mer;
                case 'r':
                    return Properties.Resources.r_black_mer;
                case 'R':
                    return Properties.Resources.r_white_mer;
                case 'n':
                    return Properties.Resources.n_black_mer;
                case 'N':
                    return Properties.Resources.n_white_mer;
                case 'b':
                    return Properties.Resources.b_black_mer;
                case 'B':
                    return Properties.Resources.b_white_mer;
                case '#':
                    return null;
                default:
                    return Properties.Resources.x;

            }
        }

        private void paintBoard(string board)
        {
            int i, j, z=0;

            matBoard = new Button[BOARD_SIZE, BOARD_SIZE];


            
            Button newBtn;
            Point pnt;

            int currentWidth = btnBoard.Location.X;
            int currentHeight = btnBoard.Location.Y;
            
            bool isColBlack = true;
            bool isRowBlack = true ;
            
            this.SuspendLayout();

            lblCurrentPlayer.Text = isCurPlWhite ? "White" : "Black";
            lblCurrentPlayer.ForeColor = isCurPlWhite ? System.Drawing.Color.White : System.Drawing.Color.Black;

            for (i = 0; i < BOARD_SIZE; i++)
            {
                currentWidth = btnBoard.Location.X;
                isColBlack = isRowBlack;

                for (j = 0; j < BOARD_SIZE; j++)
                {
                    newBtn = new Button();
                    matBoard[i, j] = newBtn;

                    if (!isMer)
                    {
                        btnBoard.FlatAppearance.MouseOverBackColor = Color.LightGreen;
                        newBtn.FlatAppearance.MouseOverBackColor = btnBoard.FlatAppearance.MouseOverBackColor;
                        newBtn.BackColor = isColBlack ? Color.Khaki : Color.SaddleBrown;
                        newBtn.FlatAppearance.BorderColor = btnBoard.FlatAppearance.BorderColor;
                        newBtn.FlatAppearance.BorderSize = btnBoard.FlatAppearance.BorderSize;
                        newBtn.FlatStyle = btnBoard.FlatStyle;
                        this.BackColor = System.Drawing.Color.Tan;

                        newBtn.Size = new System.Drawing.Size(btnBoard.Width, btnBoard.Height);
                        newBtn.Tag = new Square(i, j);
                        pnt = new Point(currentWidth, currentHeight);
                        newBtn.Location = pnt;
                        newBtn.BackgroundImageLayout = ImageLayout.Stretch;

                        newBtn.BackgroundImage = getImageBySign(board[z]);
                    }
                    else
                    {
                        btnBoard.FlatAppearance.MouseOverBackColor = Color.PeachPuff;
                        newBtn.FlatAppearance.MouseOverBackColor = btnBoard.FlatAppearance.MouseOverBackColor;
                        newBtn.BackColor = isColBlack ? Color.Aquamarine : Color.Crimson;
                        newBtn.FlatAppearance.BorderColor = btnBoard.FlatAppearance.BorderColor;
                        newBtn.FlatAppearance.BorderSize = btnBoard.FlatAppearance.BorderSize;
                        newBtn.FlatStyle = btnBoard.FlatStyle;
                        this.BackColor = System.Drawing.Color.Pink;

                        newBtn.Size = new System.Drawing.Size(btnBoard.Width, btnBoard.Height);
                        newBtn.Tag = new Square(i, j);
                        pnt = new Point(currentWidth, currentHeight);
                        newBtn.Location = pnt;
                        newBtn.BackgroundImageLayout = ImageLayout.Stretch;

                        newBtn.BackgroundImage = getMerImageBySign(board[z]);
                    }
                    
                    newBtn.Click += lastlbl_Click;

                    Controls.Add(newBtn);


                    currentWidth += btnBoard.Width;
                    isColBlack = !isColBlack;
                    z++;

                }

                isRowBlack = !isRowBlack;
                currentHeight += btnBoard.Height;

            }

            Controls.Remove(btnBoard);
            this.ResumeLayout(false);
        }

        void lastlbl_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            if (srcSquare != null)
            {
                // unselected
                if (matBoard[srcSquare.Row, srcSquare.Col] == b)
                {
                 
                    matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.Maroon;
                    srcSquare = null;
                }
                else
                {
                    dstSquare = (Square)b.Tag;
                    matBoard[dstSquare.Row, dstSquare.Col].FlatAppearance.BorderColor = Color.DarkGreen;

                    Thread t = new Thread(playMove);
                    t.Start();
                 //   t.IsBackground = true;
                    //playMove();
                }
            }
            else
            {
                srcSquare = (Square)b.Tag;
                matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.DarkGreen;
            }
         
        }

        // messages should be according the protocol.
        // index is the message number in the protocol
        string[] messages =  {
            "Valid move",
            "Valid move - you made chess",
            "Invalid move - not your player",
            "Invalid move - destination is not free",
            "Invalid move - chess wil occure",
            "Invalid move - out of bounds",
            "Invalid move - illegeal movement with piece",
            "Invalid move - source and dest are equal",
            "Game over - check mate",
            //added for castling
            "Valid move - performed Castling",
            "Valid move - performed Castling and Chess",
            "Game over - performed Castling and CheckMate",

            "Unknown message"
            };


        string convertEngineToText(string m)
        {
            int res;
            bool b = int.TryParse(m, out res);

            if (!b || res < 0 || res >= messages.Length)
                return messages[messages.Length - 1];

            return messages[res];
        }
        


        void playMove()
        {
            if (isGameOver)
                return;


            try
            {
                 Invoke((MethodInvoker)delegate {

                    lblEngineCalc.Visible = true;
            
                    lblMove.Text = string.Format("Move from {0} to {1}", srcSquare, dstSquare);
                    lblMove.Visible = true;
                    //lblEngineCalc.Invalidate();
            
                    label2.Visible = false;
                    lblResult.Visible = false;

                    this.Refresh();
            

                    // should send pipe to engine
                    enginePipe.sendEngineMove(srcSquare.ToString() + dstSquare.ToString());


                     // should get pipe from engine
                    string m = enginePipe.getEngineMessage();
                    if(m == "a")
                     {
                         m = "10";
                     }
                    else if(m == "b")
                     {
                         m = "11";
                     }

                    if (!enginePipe.isConnected())
                    {
                        MessageBox.Show("Connection to engine has lost. Bye bye.");
                        this.Close();
                        return;
                    }

                    string res = convertEngineToText(m);

                    if (res.ToLower().StartsWith("valid") || res.ToLower().StartsWith("game over"))
                    {
                        isCurPlWhite = !isCurPlWhite;
                        lblCurrentPlayer.Text = isCurPlWhite ? "White" : "Black";
                         lblCurrentPlayer.ForeColor = isCurPlWhite ? System.Drawing.Color.White : System.Drawing.Color.Black;

                         if (res.ToLower().Contains("castling"))
                         {
                             //four options for castling, check which one it is.
                             if(srcSquare.ToString() + dstSquare.ToString() == "d1b1")
                             {
                                 matBoard[7, 2].BackgroundImage = matBoard[7, 0].BackgroundImage;
                                 matBoard[7, 0].BackgroundImage = null;
                                 matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                                 matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = null;
                             }
                             else if (srcSquare.ToString() + dstSquare.ToString() == "d1f1")
                             {
                                 matBoard[7, 4].BackgroundImage = matBoard[7, 7].BackgroundImage;
                                 matBoard[7, 7].BackgroundImage = null;
                                 matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                                 matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = null;
                             }
                             else if (srcSquare.ToString() + dstSquare.ToString() == "d8b8")
                             {
                                 matBoard[0, 2].BackgroundImage = matBoard[0, 0].BackgroundImage;
                                 matBoard[0, 0].BackgroundImage = null;
                                 matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                                 matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = null;
                             }
                             else if (srcSquare.ToString() + dstSquare.ToString() == "d8f8")
                             {
                                 matBoard[0, 4].BackgroundImage = matBoard[0, 7].BackgroundImage;
                                 matBoard[0, 7].BackgroundImage = null;
                                 matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                                 matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = null;
                             }
                             /*
                             temp = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                             matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage;
                             matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = temp;
                             */
                         }
                         else
                         {
                             matBoard[dstSquare.Row, dstSquare.Col].BackgroundImage = matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage;
                             matBoard[srcSquare.Row, srcSquare.Col].BackgroundImage = null;
                         }

                        matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.Maroon;
                        matBoard[dstSquare.Row, dstSquare.Col].FlatAppearance.BorderColor = Color.Maroon;
                         //still do last move, just stop sfter it.
                         if (res.ToLower().StartsWith("game over"))
                         {
                             if(isCurPlWhite)
                             {
                                 res += "\n\nBlack ";
                             }
                             else
                             {
                                 res += "\n\nWhite ";
                             }
                             res += "Won!";
                             isGameOver = true;
                             enginePipe.sendEngineMove("quit");
                         }
                     }

                    lblEngineCalc.Visible = false;
                    lblResult.Text = string.Format("{0}", res);
                    lblResult.Visible = true;
                    label2.Visible = true;
                    this.Refresh();
                 });
                
           
                }
                catch
                {

                }
                finally
                {
                    Invoke((MethodInvoker)delegate
                    {
                        if (srcSquare != null)
                            matBoard[srcSquare.Row, srcSquare.Col].FlatAppearance.BorderColor = Color.Maroon;

                        if (dstSquare != null)
                            matBoard[dstSquare.Row, dstSquare.Col].FlatAppearance.BorderColor = Color.Maroon;

                        dstSquare = null;
                        srcSquare = null;

                    });
                }

        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            enginePipe.sendEngineMove("quit");
            enginePipe.close();
        }

        private void changeSkin_Click(object sender, EventArgs e)
        {
            if(!gameStarted)
            {
                isMer = !isMer;
                skinType.Text = isMer ? "Magical Sea vs. Sky" : "8-Bit";
            }
            else
            {
                MessageBox.Show("Sorry, game already started.");
            }
            
        }
        private void lblCurrentPlayer_Click(object sender, EventArgs e)
        {

        }

        private void btnBoard_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void lblWaiting_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void lblEngineCalc_Click(object sender, EventArgs e)
        {

        }

        private void lblResult_Click(object sender, EventArgs e)
        {

        }

    }
}
