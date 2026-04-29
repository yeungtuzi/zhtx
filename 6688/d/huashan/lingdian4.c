//lingdian4 东侧殿
inherit ROOM;

string look_picture();

void create()
{
	set("short","东侧殿");
	set("long",
@LONG
你走进了濪灵殿的东侧殿，奇怪，这里居然什么东西都没有，只有最左
的墙上挂着一条三清画像。画像前面放着一张大大的供桌。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"lingdian1",
		
]));
        
	set("item_desc", ([
                "picture": (: look_picture :),
                "画像"   : (: look_picture :),
                "三清画像": (: look_picture :),
        ]));

	setup();
}

void init()
{
	 add_action("do_push","push");	
}

string look_picture()
{
	return "奇怪，这幅三清画像也很是古怪，本来该在左边的太上老君却画在右边，右边的灵宝道君却画在了中间\n";
		
}

int do_push()
{
  	object room;
  	
  	object ppl=this_player();
        if(!(room = find_object(__DIR__"lingdian3")))
             room = new(__DIR__"lingdian3");
        if( room->query("can_push") != 1)
            return notify_fail("你试图去推三清画像，可是这幅画像纹丝不动。\n");
/*
        if(!room->query("pusher")==ppl->query("id"))
            return notify_fail("你试图去推三清画像，可是这幅画像纹丝不动。\n");
	if(!ppl->query_condition("rest_time"))
	    {
		ppl->set_temp("last_damage_from",ppl);
		ppl->set_temp("die/reason","被乱箭齐发射死了！");
		ppl->set_temp("die/place",query("short"));
		ppl->die();
		return 1;
	    }
*/
        message_vision("$N一推三清画像，居然地面上缓缓出现一个大洞。\n", ppl);
        set("exits/down", __DIR__"mishi");
        if(!(room = find_object(__DIR__"mishi")))
             room = new(__DIR__"mishi");
        message("vision", "有人从外面把机关打开啦。\n", room);
	remove_call_out("close_door");
	call_out("close_door",10);
	return 1;
}
void close_door()
{
        object room;

        if( !( room = find_object(__DIR__"mishi")) )
           room = load_object(__DIR__"mishi");
        if(objectp(room))
        {
                delete("exits/down");
                message("vision", "地上的大洞又自动合上了。\n", this_object());
        }
        else message("vision", "ERROR: men not found(close).\n", room);
}

