/*--
		Flag Base
		Author: Maikel
		
		A base for the CTF goal, flags can be stolen here, and players must bring flags of opposing teams here.
--*/


local team;

public func SetTeam(int to_team)
{
	if (!to_team)
		return;
	team = to_team;
	UpdateColor();
	return;
}

public func GetTeam()
{
	return team;
}

public func FindTeam(int find_team)
{
	if (!find_team || !team)
		return false;
	return team == find_team;
}

// Returns whether there is a flag at this base.
public func IsBaseWithFlag()
{
	return !!FindObject(Find_ID(Goal_Flag), Find_Func("FindTeam", team), Find_Distance(30));
}

private func UpdateColor()
{
	//SetClrModulation(GetTeamColor(team));
}

local Name = "Flagbase";