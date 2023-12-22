#include "Validate.h"
void Validate::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Validate : Checking the FlowChart");

}
void Validate::Execute()
{
	ReadActionParameters();

}
bool Validate::IsValidated()
{
	return Validate_Status;
}