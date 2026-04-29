//hshouyuan.c  华山后院
//by emote
inherit ROOM;

void create()
{
	set("short","华山后院");
	set("long",
@LONG
这里是后院，华山派的二弟子劳德诺和三弟子梁发正在这里相互切磋功
夫。他们正练至酣处，连你的到来都没注意到。西北方似乎有条小路通
往山上。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"southeast"  : __DIR__"xiaolu4",
		"north" : __DIR__"zhengqitang",
		
]));
        set("objects", ([
                 __DIR__"npc/liang":1,
				 __DIR__"npc/lao":1,
				 
]));
        set("item_desc", ([
                "小路": "那是一条通向山里的小路，似乎没有尽头。\n"
        ]) );
		set("outdoors","huashan");
        set("no_clean_up", 0);
		setup();
}
void init()
{
        add_action("do_northwest", "northwest");
}

int do_northwest()
{
        object me;
        me = this_player();

        if( me->query_temp("marks/思1") || me->query("family/master_id")=="feng qingyang") 
        if( me->query_temp("marks/思1") || me->query("family/master_id")=="feng qingyang") 
        {
                message("vision",me->name() + "向西北的小路走去。\n", environment(me), ({me}) );
                me->move("/d/huashan/siguoya");
                message("vision", me->name() + "走向西北的小路。\n",  environment(me), ({me}) );
                return 1;
        }
        else {
                write("那条小路似乎没有尽头。\n");
                return 1;
                }
}


