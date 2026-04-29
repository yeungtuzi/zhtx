// zhongting.c

inherit ROOM;
int do_enter(string arg);
void create()
{
        set("short", "华山别院--庭院");
        set("long", @LONG
这里就是华山别院大院所在。华山剑气二宗相争后，剑宗一败涂
地，让出掌门之位后在此苦练。这里的大院里面种着许多的槐树，有
一株特别高大，看起来挺神秘的样子，不知道有什么秘密在里面。华
山剑宗的一位弟子正在这里指导其他弟子们一些入门的功夫。左边的
一间大屋是剑宗长老成不忧的居所，右边的就是当今剑宗掌门封不平
的居所了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"bieyuan",
		"north" : __DIR__"zhengting",
		"west"  : __DIR__"chengroom",
		"east"  : __DIR__"fengroom",
]));
        set("out_doors","huashan"); 
        set("objects", ([
                (__DIR__"npc/dizi1"):1,
                (__DIR__"npc/dizi") : 3]));
        set("item_desc",([
               "tree" : "这是一棵高大茂盛的大槐树，上面有个大树洞，也许里面有什么秘密。\n",
               "槐树" : "这是一棵高大茂盛的大槐树，上面有个大树洞，也许里面有什么秘密。\n",
        ]));
        setup();
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}


void init()
{
    add_action("do_enter","enter");
}
int do_enter(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 1;
        if( arg=="hole" ) 
        {
                message_vision("$N一猫腰往洞里哧溜一声飞快地钻了进去。\n",me,me);
                me->move(__DIR__"hole0");
                return 1;
        }
}       
 
     
