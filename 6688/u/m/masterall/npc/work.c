// /d/xizang/work.c
//#include "/feature/damage.c"

#include <skill.h>
inherit ROOM;

void comehere(object me);
void time_to_go(object ob);

void create()
{
        set("short", "采石场");
        set("long", @LONG
恰克卜里山盛产各种上等石料。这里硝烟弥漫，很多人都在辛苦的劳动着。
用自己的汗水去换取一些收入。每个到这里工作的人都可以拿到一份很公平的
报酬。许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"xiaolu",
  "southwest" : __DIR__"y_road",
]));

        set("item_desc", ([
                "sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。

work     开始工作。

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
        set("objects", ([
                __DIR__"npc/wangdui" : 1,
                __DIR__"npc/worker" : random(3),
        ]));
        setup();
}

void init()
{
//        remove_action("do_work", "work");
        add_action("do_work", "work");
        add_action("do_yell", "yell");
}

int do_work(string arg)
{
        object ob;
        object me;
        int temp, my_str, my_con, my_cor, my_kar, skill;
        me = this_player();

        if( me->query("gin") < 50 || me->query("sen") < 50 )
                return notify_fail("你现在累着呢，歇歇吧。\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");

        message_vision(HIM"$N辛苦的工作终于结束了，可人也累的要死。\n"NOR, me);

        me->add("gin",-30);
        me->add("sen",-30);
        my_kar = me->query("kar");


// an accident, also a chance to improve courage
        if ( random(31) > 29 ) {
         message_vision(HIR"$N大叫一声：“不好!”随即从悬崖峭壁上摔了下来!!\n"NOR,me);
         skill = me->query("dodge", 1);

// lucky or dodge can avoid damage
         if ( random (my_kar) < 29 ) {
         message_vision(HIR"$N被摔得头破血流，眼前一黑，倒在血泊之中！\n"NOR,me);
         me->unconcious();

         } else {
         message_vision(HIG"$N真是好运气,居然没受什么伤.\n"NOR,me);
         message_vision(HIC"$N大难不死,觉得自己的胆量有所提高！\n"NOR,me);
         me->add("cor", 1);
         if ( me->query("cor")> 50) me->set("cor",50);
         }

         }

// assume using hammer in stone work
        if( me->query_skill("hammer",1) < 50 )
                me->improve_skill("hammer", random(my_str)/2 +1 );

// pay money here
        ob = new(OBJ_DIR"money/silver");
        ob->move(me);
        write("这是你的工钱。\n");
        return 1;
}

int do_yell(string arg)
{
        object me;
        if(!arg || (arg!="大雄"))
                return notify_fail("你喊破了嗓子,就是没人理你.\n");
        me=this_player();
        if(random(31)>25){
        message_vision("$N听到大雄在崖上应道: 忙着呢,等一会儿!\n", me);
        return 1;
        }
        message_vision("$N听到大雄在崖上应道: 就来了!\n", me);
        call_out("comehere", 1, me);
        return 1;
}

void comehere(object me)
{
        object ob;
        if(environment(me)!=this_object()) return;
        if(objectp(ob=present("daxiong", this_object())))
                return;
        message_vision("$N看到一条大汉从悬崖上攀援而下.\n", me);
        ob=new(__DIR__"npc/daxiong");
        ob->move(this_object());
        call_out("time_to_go", 20, ob);
}

void time_to_go(object ob)
{
        if(!objectp(ob)) return;
        ob->say("大雄说道: 我得去干活儿了.\n");
        destruct(ob);
}

