
inherit ROOM;

void create()
{
	set("short", "巨木旗神木");
	set("long", @LONG

你眼前只见一棵大树，高有百丈，十人也环抱不住。巨树倚绝壁而
生，枝叶繁茂，藤萝环绕，竟然无法一览全貌。树身有一处光滑无
比，是常有人摩挲而成。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jmqshulin6",
	]));

	set("outdoors", "mingjiao");

	setup();

}

void init()
{
        add_action("do_open", "touch");
}
int do_open(string arg)
{
        // 2026-04-30: unused variable commented out
        // object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "tree" || arg == "神木")
        {
        me = this_player();
        message_vision("$N俯身走了两步，伸手摩挲了一下神木，＂呀＂地一声，神木的底部，竟裂开了一重门户。\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"secretpath0");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你伸手扳了扳"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"神木上的门户又无声无息的合了起来．\n",
                this_object() );
                delete("exits/down");
}

