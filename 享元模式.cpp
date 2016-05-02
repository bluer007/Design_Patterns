/*
*	享元模式	源文件
*/


#include <iostream>
#include <map>
#include <vector>
#include "享元模式.h"

using namespace std;

namespace xy
{			
	enum Color : int 
	{
		WHILE = 0,
		BLACK = 1
	};
	
	struct  Pos 
	{
		int x;
		int y;
		
		Pos(int ix = 0, int iy = 0) : x(ix), y(iy) {};

		//重载<, 让Pos可以作为map的元素
		bool operator < (const Pos& other) const
		{
			if (this->x < other.x)
			{
				return true;
			}
			return false;
		};
	};

	//基类, 定义基本的内部属性和外部属性
	class Piece
	{
	public:
		Piece(Color color) : m_color(color)
		{
				
		};

		//内在属性的存储接口
		void SetPos(Pos pos)
		{
			this->m_pos = pos;
		};

		Color GetColor()
		{
			return m_color;
		}

		//通过该接口, 把pos这外在属性转移到ChessBoard类中存储
		Pos GetPos()
		{
			return m_pos;
		}

	private:
		Pos m_pos;			//外在属性, 在享元模式中, 则最终存储在其他类(ChessBoard类)中
		Color m_color;		//内在属性, 在享元模式中, 则存储在自身类中
	};

	//继承Piece, 可以实现自己想要的其他操作
	class GoChess : public Piece
	{
	public:
		GoChess(Color color) : Piece(color) {};
	};

	class ChessBoard
	{
	public:
		void Draw(Piece* piece)
		{
			if (WHILE == piece->GetColor())
			{
				cout << "this is while piece, pos is " << (piece->GetPos()).x 
					<< ":" << (piece->GetPos()).y << endl;
			}
			else
			{
				cout << "this is black piece, pos is " << (piece->GetPos()).x 
					<< ":" << (piece->GetPos()).y << endl;
			}
			m_chessboard.insert(pair<Pos, Piece*>(piece->GetPos(), piece));
		}

		void DrawAllPiece()
		{
			map<Pos, Piece*>::iterator ite;
			for (ite = m_chessboard.begin(); ite != m_chessboard.end(); ite++)
			{
				if (WHILE == ite->second->GetColor())
				{
				cout << ite->first.x << ":" << ite->first.y 
					<< " has a while piece" << endl;
				}
				else
				{
				cout << ite->first.x << ":" << ite->first.y 
					<< " has a black piece" << endl;
				}
			}
		}

 private:
		map<Pos, Piece*> m_chessboard;
	};

	class PieceFactory
	{
	public:
		PieceFactory() {}
		
		~PieceFactory()
		{
			for (vector<Piece*>::iterator ite = m_piece.begin(); ite != m_piece.end(); ite++)
			{
				delete *ite;
			}
			m_piece.clear();
		}

		Piece* GetPiece(Color color)
		{
			Piece* piece = nullptr;
			if (m_piece.empty())
			{
				piece = new GoChess(color);
				m_piece.push_back(piece);
			}
									
			for (vector<Piece*>::iterator ite = m_piece.begin(); ite != m_piece.end(); ite++)
			{
				if ((*ite)->GetColor() == color)
				{
					piece = *ite;
					break;
				}
			}

			if (!piece)
			{
				piece = new GoChess(color);
				m_piece.push_back(piece);
			}
			
			return piece;
		}

	private:
		vector<Piece*> m_piece;
	};

	void test_xy()
	{
		//本例子中的效果是, 工厂类创建了"逻辑"上的三个棋子,
		//实际上却只有两个对象, 一个"黑子",一个"白子"
		//颜色信息作为内在属性(不变属性), 存储在Piece中
		//位置信息作为外在属性(变化属性), 存储在ChessBoard类中
		//避免了创建大量重复的对象--棋子

		cout << "\n----享元模式----\n";
		PieceFactory* factory = new PieceFactory();
		ChessBoard* chessboard = new ChessBoard();

		Piece* piece = factory->GetPiece(WHILE); 
		piece->SetPos(Pos(1, 2));
		chessboard->Draw(piece);

		piece = factory->GetPiece(BLACK);
		piece->SetPos(Pos(3, 4));
		chessboard->Draw(piece);
		
		piece = factory->GetPiece(WHILE); 
		piece->SetPos(Pos(5, 6));
		chessboard->Draw(piece);
	
		cout << endl << "start draw all pieces..." << endl;
		chessboard->DrawAllPiece();

		delete factory;
		delete chessboard;
	};
};
