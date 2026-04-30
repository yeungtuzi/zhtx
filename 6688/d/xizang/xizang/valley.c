// /d/xizang/valley.c

inherit ROOM;

string look_figure();
void open_passage();
void close_passage();

void create()
{
        set("short", "绝崖下");
        set("long", @LONG
这里是万丈深渊的底部,看上去象是一处死地,四面峭壁如削,寸草不生.除了
几只飞鸟从空中掠过,周围死气沉沉,全无生机.迎面一块大石(stone)上似乎端坐
着一个红色身影(figure),不知是人是鬼.
LONG
        );
        set("outdoors", "xizang");
	set("item_desc", ([
		"stone" : "这是一块万钧巨石,阻住了看上去是出路的地方.\n",
		"figure" : (: look_figure :),
	]));
        set("objects", ([
                __DIR__"npc/redlama" : 1,
        ]) );
        setup();
}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        // 2026-04-30: unused variable commented out
        // object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "valley" || arg == "up" || arg == "绝崖"
                || arg == "峭壁")
        {
        me = this_player();
        message_vision("$N抓着突出的石角，慢慢的顺着崖壁爬了上去。\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        me->move(__DIR__"cliff");
        message_vision("$N顺着崖壁爬了上来。\n", me);
        return 1;
}

string look_figure()
{
	object ob;
	ob = present("chi_song_lama", this_object());
	if (!ob || !objectp(ob) ) 
	return "你仔细地又看了看,石上却没有什么人,看来你是眼花了.\n";
	if (living(ob)) 
return "这人形容枯瘦,死多活少,只有一双眼睛偶尔转动一下,表示他还活着.\n";
return "这人已经差不多是一具干尸了.\n";
}

void open_passage()
{
	object ob;
	message("vision","赤松拨开巨石上的藤蔓,露出一个洞口.\n",
		this_object() );
	set("exits/southup", "/d/xizang/class/bad/entrance");
        if (ob = find_object("/d/xizang/class/bad/entrance")) {
           ob->set("exits/northdown", "/d/xizang/valley");
           message("vision","巨石上的藤蔓摇动了一阵,似乎有人要爬进来.\n", ob);
	}
	call_out("close_passage", 10);
}

void close_passage()
{
        // 2026-04-30: unused variable commented out
        // object room;

        if( !query("exits/southup") ) return;
        message("vision","一阵风吹来,藤蔓飘回原位,盖住了洞口.\n",
		this_object() );
	delete("exits/southup");
}
