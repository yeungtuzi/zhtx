
inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
道路在这里已经到了尽头，只有路边的野草在随风而舞。有
一段的草丛较为稀落，似是常有人从上面经过。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"tohtq1",
	]));

	set("outdoors", "mingjiao");

	setup();

}

void init()
{
        add_action("do_open", "push");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要拨开什么？\n");
                return 1;
        }
        if( arg == "grass" || arg == "野草")
        {
        me = this_player();
        message_vision("$N俯身分开草丛，发现了一条向下的地道。\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"tohtq3");
        call_out("close_path", 5);
        }
        return 1;
        }
        else
        {
                write("你伸手碰了碰"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision","地道口又无声无息的合了起来．\n",
                this_object() );
                delete("exits/down");
}

