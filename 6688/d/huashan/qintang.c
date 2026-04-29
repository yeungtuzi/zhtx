// qintang.c

inherit ROOM;

void create()
{
        set("short", "琴堂");
        set("long", @LONG
房间并不大，但很整洁。一个老者怀拥瑶琴，似乎在想着什么。这里就是黄钟公
的卧室。室内一床一几，陈设简单，床上挂了纱帐，甚是陈旧，已呈黄色。几上放着
还有一张短琴，通体黝黑，似是铁制。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"southwest"  : __DIR__"zoulang1",
]));
        
        set("objects", ([
                (__DIR__"npc/huangzhong"):1,
                ]));
        set("have_searched",0);
        set("have_uncovered",0);
        setup();
    //    replace_program(ROOM);
}
void init()
{
    add_action("do_pull","pull");
    add_action("do_uncover","uncover");
    add_action("do_search","search");
}
int do_uncover(string arg)
{
       object me;
       me=this_player();
       if(!arg||arg=="")
       return notify_fail("你想掀开什么？\n");
       if(!me->query("win_huangzhong"))
       return notify_fail("你想掀别人的床，搞笑吧。\n");
       if(arg=="被褥")
       message_vision("$N掀开了床上的被褥。\n",me,me);
       me->start_busy(5);
       set("have_uncovered",1);
       return 1;
}

int do_search(string arg)
{
       object me;
       me=this_player();
       if(!arg||arg=="")
       return notify_fail("你想搜索什么？\n");
       if(!me->query("win_huangzhong"))
       return notify_fail("人家的房间，这么乱搜一气不好吧。\n");
       if(!query("have_uncovered"))
       return notify_fail("你乱搜什么啊。把人家的床都搞乱了，讲点道德好不好。\n");
       if(arg=="床板")
       tell_object(me,"你开始搜索这里的床板。\n");
       if(query("have_searched"))
       return notify_fail("结果什么也没有搜到。\n");
       if(random(me->query("kar"))>8)
       {
       	me->set_temp("mark/searched_ring",1);
       	set("have_searched",1);
       	tell_object(me,"你找到了一块铁板，似乎很沉重的样子，下面看来覆盖了什么东西。\n");
       	return 1;       	
       }
       set("have_searched",1);
       return notify_fail("结果什么也没有搜到。\n");
}
int do_pull(string arg)
{
     object me,room;
     me=this_player();
     if(!arg||arg=="")
     return notify_fail("什么？你想干什么？\n");
     if(arg=="铜环")
     {
       if(((int)me->query("force_factor")+(int)me->query_("str")<150))
       return notify_fail("你使劲地拉着铜环，可惜铁板太重了，你怎么拉也拉不动。\n");
       else
       {
       	message_vision("$N拉着铁板上的铜环，用力地把铁板拉了开来。\n",me,me);
        set("exits/down", __DIR__"laomen");
        if( room = find_object(__DIR__"laomen") ) {
                        room->set("exits/up", __FILE__);
                        message("vision", 
"头顶上的铁板忽然发出轧轧的声音，露出一个光亮亮的洞口。"
"一块块踏脚石从墙壁中凸了出来，形成一个向上的阶梯。\n",room );
                }
        remove_call_out("close_path");
        call_out("close_path",10,);
       }
    }
    return 1;
}
void close_path()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision", "铁板忽然咣的一下倒下了，将向下的洞口盖住了。\n", this_object() );
        if( room = find_object(__DIR__"laomen") ) {
                room->delete("exits/up");
                message("vision", "头顶上的铁板咣的一下倒下了，盖住了向上的出口。\n", room );
        }
        delete("exits/down");
}


