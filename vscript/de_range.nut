if( GetDeveloperLevel() > 0 )
	printl( "Initializing de_range.nut" );

function Start_Test()
{
	// Do stuff when the button is pressed!

	// Send a message to the chat.
	ScriptPrintMessageChatAll("Skill Test");

	// Change the model of the player that uses the button!
	//activator.SetModel("models/props_junk/watermelon01.mdl");

	// Send a command to the console.
	//SendToConsole("sv_cheats 1");
	//SendToConsole("thirdperson");

	// Send a message to the console. (useful for debugging!)
	printl("ButtonPressed() has been executed!")
}
