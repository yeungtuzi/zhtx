// Room: xiuxishi.c
// By Marz

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
        set("short", "休息室");
        set("long", @LONG
        这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG
        );
	set("exits",([
		"east" : __DIR__"wallhole"
		]));
        set("sleep_room", 1);
	set("no_faint",1);
	set("family","大招寺");
        set("no_fight", 1);

        setup();
}

/*	int valid_leave(object me, string dir)
{
	object room;

	if ( !::valid_leave(me, dir) ) 
		return 0;
	
	if(!(room = find_object(__FILE__)) )
		room = load_object(__FILE__);
	if(objectp(room))
	{
		room->add_temp("person_inside", -1);	
		if ((int)room->add_temp("person_inside", -1) <= 0)
			room->delete_temp("person_inside");	
	}
	
	return 1;
}*/
