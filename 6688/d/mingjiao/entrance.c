
inherit ROOM;

void create()
{
        set("short", "羊肠小道");
        set("long", @LONG
	一条小道弯弯曲曲的向北面的山幽伸展。道旁的茅草高达五尺，遮住了
天光。山幽中的一切都显的阴森幽暗。美丽的蝴蝶四散飞舞。这里的茅草(grass)
似乎更密更厚了。
LONG
        );
        set("exits", ([ 
  	"northeast" : __DIR__"tomen1", 
]));

        set("item_desc", ([
                "grass": "这里的茅草(grass)很密，但你似乎可以拨开(pushaside)它们。\n",
                "茅草": "这里的茅草(grass)很密，但你似乎可以拨开(pushaside)它们。\n"

        ]) );

        set("outdoors", "mingjiao");
        setup();
}
void init()
{
        add_action("do_push", "pushaside");
}
int do_push(string arg)
{
        // 2026-04-30: unused variable commented out
        // object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要拨开什么？\n");
                return 1;
        }
        if( arg == "grass" || arg == "茅草" || arg == "草")
        {
        me = this_player();
        message_vision("$N拨开路边的茅草，发现了一条向北的路。\n", me);
	if( !query("exits/north") ) {
	set("exits/north", __DIR__"bridge");
	call_out("close_path", 5);
	}
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"一阵风吹过，茅草晃了晃，又淹没了向北的路。\n",
                this_object() );
		delete("exits/north");
}
