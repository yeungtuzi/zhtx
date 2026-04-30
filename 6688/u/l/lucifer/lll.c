inherit ROOM;
#include <ansi.h>

void open_passage();
void close_passage();

void create()
{
        set("short", HIW"黑店"NOR);
        set("long", @LONG
这是茅山小道与小桂子两口子新开的黑店，据说费用奇高。
    正中墙上挂着一个菜单(menu), 一个漂亮能干的服务员阿姨（小桂子？）
正在忙里忙外的招呼客人，你可以点(order)你想要的东西。
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "menu" : "天仙玉露，菩提子，金蚕王，怒龙锦胄，九花玉露丸，人参果，月光宝盒。\n",
  "菜单" : "天仙玉露，菩提子，金蚕王，怒龙锦胄，九花玉露丸，人参果，月光宝盒。\n",
]);
        set("no_fight", 1);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/waiter" : 1,
  __DIR__"npc/husband" : 1,
]));
        set("no_clean_up", 0);
        set("no_magic", 1);

        setup();
}

void init()
{
        add_action("do_order", "order");
        add_action("do_leave", "go");
        add_action("no_quit", "quit");
}

void init()
{       
    object ob = this_player();
    ob->delete(marks/点菜);
    ob->set("startroom", "/u/y/yydh/workroom");
         ::init();
}

int no_quit()
{
        object me;
        me = this_player();
        if (me->query("marks/点菜")) {
                tell_object(me, "你没交钱，还想溜吗? 没门儿! \n");
                message_vision("$N刚想溜，就被小桂子阿姨揪了回来! \n", me);
                return 1;
        }
        
        return 0;
}

int do_leave(string arg)
{
        object me;
        int i;
        string num;
        if (arg != "west") return 0;
        me = this_player();
        if (arg == "west") {
                if ((i = me->query("marks/点菜"))) {
                        num = sprintf("%d", i);
                        tell_object(me, "小桂子阿姨笑着对你说：你点了" + num + "道菜，请你付" + num + "两银子再走。\n");
       return 1;
                }
                else {
                        me->move("/u/y/yydh/workroom");
                        return 1;
                }
        }
        return 1;
}

int do_leave1()
{
        object me;
        int i;
        string num;
        me = this_player();
        if ((i = me->query("marks/点菜"))) {
                num = sprintf("%d", i);
                tell_object(me, "小桂子阿姨笑着对你说：你点了" + num + "道菜，请你付" + num*10000 + "两银子再走。\n");
                return 1;
        }
        me->move("/u/y/yydh/workroom");
        return 1;
}

int do_leave2()
{
        object me;
        int i;
        me = this_player();
        if ((i = me->query("marks/点菜" == 0))) {
                tell_object(me, "小桂子阿姨笑着对你说：你还没点菜，请点完菜再走。\n");
                return 1;
        }
        me->move("/u/m/mudadm/workroom");
        return 1;
}

int do_order(string arg)
{
        object me, ob, foods, soup;
        int i;
        me = this_player();
        if (!arg || arg == "") {
                write("你要点什么?\n");
                return 1;
        }
        if (arg != "天仙玉露" &&
            arg != "菩提子" &&
            arg != "九花玉露丸" &&
            arg != "人参果" &&
            arg != "怒龙锦胄" &&
            arg != "金蚕王" &&
            arg != "月光宝盒") {
                write("小桂子阿姨两手一摊说：本店没有这样东西。\n");
                return 1;
        }

        if (arg == "怒龙锦胄")
            {
                armor = new(__DIR__"obj/armor");
                armor->move(me);
              write("小桂子阿姨转身从柜子里取出一件怒龙锦胄交给你，“请付钱再走。”\n");
        }
        if (arg == "菩提子")
             {
                 zi = new(__DIR__"obj/zi");
                zi->move(me);
              write("小桂子阿姨转身从柜子里取出一件菩提子交给你，“请付钱再走。”\n");
               }
        if (arg == "九花玉露丸")
             {
                 wan = new(__DIR__"obj/wan");
                wan->move(me);
              write("小桂子阿姨转身从柜子里取出一件交给九花玉露丸你，“请付钱再走。”\n");
               }
        if (arg == "人参果")
             {
                 wan = new(__DIR__"obj/wan");
                wan->move(me);
              write("小桂子阿姨转身从柜子里取出一件交给人参果你，“请付钱再走。”\n");
               }
        if (arg == "天仙玉露")
             {
                 wan = new(__DIR__"obj/wan");
                wan->move(me);
              write("小桂子阿姨转身从柜子里取出一件交给天仙玉露你，“请付钱再走。”\n");
               }
        if (arg == "金蚕王")
             {
                 wang = new(__DIR__"obj/wang");
                wang->move(me);
              write("小桂子阿姨转身从柜子里取出一件交给金蚕王你，“请付钱再走。”\n");
               }
        if (arg == "月光宝盒")
             {
                 casket = new(__DIR__"obj/casket");
                casket->move(me);
              write("小桂子阿姨转身从柜子里取出一件交给月光宝盒你，“请付钱再走。”\n");
               }
        if (!me->query("marks/点菜")) 
                me->set("marks/点菜", 1);
        else
                me->add("marks/点菜", 1);
        message_vision("$N向服务员小姐点了一样" + arg + "。\n", me);
        return 1;
}


void open_passage()
{
    object ob;
    message("vision","茅山小道打开几道门说：“既然交钱了，走把。”\n",
            this_object() );
    set("exits/west", "/d/wizard/wizard_room");
     }
    call_out("close_passage", 10);
}

void close_passage()
{
        // 2026-04-30: unused variable commented out
        // object room;

        if( !query("exits/west") ) return;
        message("vision","“外面风又大了，茅山小道随手把门关上了。”\n",
            this_object() );
    delete("exits/west");
}

