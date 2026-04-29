///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

int do_fishing(object me);

void create()
{
        set("short", CYN"小溪边"NOR);
        set("long", @LONG
到这里路断了。面前是一条清澈的小溪，偶尔可以看见
有鱼游来游去。旁边还放着几根钓鱼杆，也不知是谁忘在这
儿的。也许你可以用它来钓鱼(fish)哦。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"szroad1",
                ]));
                set("objects", ([
                                __DIR__"npc/fishseller": 1,
                        ]));
        setup();
}

void init()
{
       add_action("do_fish", "fish");
}

int do_fish()           //钓鱼分配经验段：10000-20000
{
        object me, fish;
        int exp;

        me = this_player();
        exp=me->query("combat_exp");
        if(exp<10000) {
                        tell_object(me,CYN"刘云财上来劝住了你：你的经验还不太够，等你经验丰富点再来吧。\n"NOR);
                        return 1;
                }
        if(exp>21000) {
                        tell_object(me,CYN"刘云财上来劝住了你：在这儿钓鱼已经不会对你的成长有任何帮助了，去别的地方吧。\n"NOR);
                        return 1;
                }
                if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
        if(me->query("sen")<11)
          return notify_fail("你的精神不能集中,钓鱼可不是那么容易的事。\n");
        message_vision("$N拿起一根钓鱼杆坐在大石头上钓起鱼来……\n", me);
        me->add("sen",-5);
        me->start_busy(10);
        call_out("do_fishing",6,me);
        return 1;
}

int do_fishing(object me)
{
        object fish;
        int i;

        message_vision(YEL"$N只见鱼漂猛然一动，急忙提杆…\n"NOR,me);
        me->interrupt_me(me,"death");
        i=random(100);

        if (i>92) {
                message_vision("$N钓到了一条"+HIY"金鲤鱼"NOR+"！\n", me);
                fish = new(__DIR__"obj/gfish");
                fish->move(me);
                me->add("combat_exp",150);
                me->add("potential",60);
                me->improve_skill("force", 50);
                return 1;
        }
        if (i>70) {
                message_vision("$N钓到了一条大鲤鱼！\n", me);
                fish = new(__DIR__"obj/fish");
                fish->move(me);
                me->add("combat_exp",75);
                                me->add("potential",30);
                                me->improve_skill("force", 25);
                return 1;
        }
        if (i>45) {
                                message_vision("$N钓到了一条小鱼。\n", me);
                                fish = new(__DIR__"obj/lfish");
                                fish->move(me);
                                me->add("combat_exp",40);
                                                me->add("potential",15);
                                                me->improve_skill("force", 15);
                                return 1;
        }
        else{
                message_vision("$N什么也没钓到。\n",me );
            }
        return 1;
}

