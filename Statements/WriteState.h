#include "Statement.h"

class WriteState : public Statement
{
	private:
		string Variable;
		Connector* pOutConn;	     //Write Stat. has one Connector to next statement

		Point LeftCorner;	//top left corner of the statement block

		virtual void UpdateStatementText();

	public:
		//============================ Class functions ============================
		WriteState(Point Lcorner, string var = "");
		void SetVariable(string var);

		~WriteState();
		//============================ Pure Virtual functions implementation ============================
		void Draw(Output* pOut) const;
		bool IsPointClicked(Point P) const;
		virtual void Simulate();						//Execute the statement in the simulation mode
		virtual void Save(ofstream& OutFile);			//Save the Statement parameters to a file
		virtual void Load(ifstream& Infile);			//Load the Statement parameters from a file
		virtual Statement* Copy();						//copy statement and return a pointer of type statement	
};