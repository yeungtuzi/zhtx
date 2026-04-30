// /d/xizang/class/budala/misc2.c

inherit ROOM;

void kill_you(object me);
void check_trigger();
void create()
{
        set("short", "杂役房");
        set("long", @LONG
这里是为布达拉宫的工作的工匠杂役们居住的地方,有些脏乱.一张简陋的
木板床(bed)上散放着些衣物(clothes).
LONG
        );
	set("item_desc", ([
		"bed" : "一张简陋的木板床,摇摇晃晃的.\n",
	    "clothes" : "一大堆脏兮兮的衣服,散发着汗和不知别的什么的味道.\n",
	]));
        set("exits", ([
          "south" : __DIR__"path7",
]));
        setup();
}

void init()
{
	delete("trigger_push");
	remove_action("do_push", "push");
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;
        // 2026-04-30: unused variable commented out
        // string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="bed") 
	{
		write("你用力推着木板床,床脚在地面摩擦发出难听的声音.\n");
		add("trigger_push", 1);
	}
	me = this_player();
	if( (random(30)>15) && random(me->query("kar"))<15 )
	{
		write("你听到屋外传来急促的脚步声,有人来了!\n");
		call_out("kill_you", random(10), me);
	}
	check_trigger();
	return 1;
}

void kill_you(object me)
{
	object ob;
	ob = new(__DIR__"npc/spy");
	ob->move(environment(me));
	ob->kill_ob(me);
	me->fight_ob(ob);
}

void check_trigger()
{
        object room;
	if ( (int)query("push_trigger")== 13
		&&      !query("exits/down") ) {
                message("vision",
"地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
                        this_object() );
                set("exits/down", __DIR__"secret");
                if( room = find_object(__DIR__"secret") ) {
                        room->set("exits/up", __FILE__);
                        message("vision",
"天花板忽然发出轧轧的声音，露出一个向上的阶梯。\n",
                                room );
                }
		delete("push_trigger");
	call_out("close_passage", 10);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision",
"地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖住了。\n",
                this_object() );
        if( room = find_object(__DIR__"secret") ) {
                room->delete("exits/up");
                message("vision",
"天花板忽然发出轧轧的声音，向上的阶梯又缓缓地收了回去。\n",
                        room );
        }
        delete("exits/down");
}

