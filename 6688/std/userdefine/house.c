inherit ROOM;
inherit USER_ROOM_TEMPLETE;

void create()
{
	if( !restore() )
	{
		set("sleep_room", 1);         
		set("no_fight",1);
		set("no_steel",1);
		set("owner","NONE");
		set("exits", ([ /* sizeof() == 1 */
  		"out" : "/d/road/kaifeng",
		]));
		set("short", "温馨的家");
		set("long", 
			"这是一个温馨的家, 需要主人来布置(depict)。\n");  			
	}	                                                                	
	setup();
}
