///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

nosave string * huntlist=({"deer","sparrow","butterfly","hare","pheasant","cat","tortoise","pangolin","bird","squirrel"});

void init()
{
       add_action("do_hunt", "hunt");
}

int do_hunt()           //打猎分配经验段：20000-50000
{
        object me, bow;
        int exp;

        me = this_player();
        exp=me->query("combat_exp");
        bow=me->query_temp("weapon");
        if(exp<20000) {
                        tell_object(me,HIC"突然旁边一个人上来劝住了你：你的经验还不太够，等你经验丰富点再来吧。\n"NOR);
                        return 1;
                }
        if(exp>50000) {
                        tell_object(me,HIC"突然旁边一个人上来劝住了你：在这儿打猎已经不会对你的成长有任何帮助了，你还是去别的地方吧。\n"NOR);
                        return 1;
                }
                if (me->is_busy()) {
                        tell_object(me,"你现在正忙着呢！\n");
                        return 1;
                }
        if(me->query("sen")<11) {
                                  tell_object(me,"你的精神不能集中,打猎可不是那么容易的事。\n");
                                  return 1;
                  }
                   if(me->query("kee")<11) {
                                                  tell_object(me,"你太累了，歇歇吧。\n");
                                                  return 1;
                  }
       if(!bow || bow->query("name")!="猎弓") {
                        tell_object(me,"没有猎弓怎么打猎？！\n");
                        return 1;
                }
        message_vision(HIB"$N开始仔细搜索这儿的树丛……\n"NOR, me);
        me->add("sen",-5);
        me->add("kee",-10);
        me->start_busy(10);
        call_out("do_searching",6,me);
        return 1;
}

int do_searching(object me)
{
        object victim;
        me->interrupt_me(me,"death");
        if(random(10)<2) {
                tell_object(me,"你什么也没发现，看来运气不太好哦。\n");
                return 1;
        }
        victim=new(__DIR__"obj/quarries/"+huntlist[random(sizeof(huntlist))]);
        if(!victim) {   //have some bug here?
                tell_object(me,"你什么也没发现，看来运气真的不太好哦。\n");
                                return 1;
        }
        tell_object(me,YEL"你突然觉得远处有什么东西动了一下！仔细一看，原来是\n"
                                "一"+victim->query("unit")+victim->query("name")+NOR"！\n");
        message_vision("$N举起手中的猎弓，低着身子慢慢向"+victim->query("name")+"接近.......\n",me);
        me->add("sen",-5);
        me->start_busy(10);
        call_out("do_hunting",6,me,victim);
}

int do_hunting(object me, object victim)
{
        me->interrupt_me(me,"death");
        if(random(100)<victim->query("dex")) {  //猎物dex越高越容易跑掉
                switch(random(2)) {
                        case 0:
                tell_object(me,HIC"哎呀！不好！"+victim->query("name")+HIC"好像发现了身边的危险，一下子窜到树丛中，消失的无影无踪。\n"NOR);
                break;
                        case 1:
                tell_object(me,"你举起猎弓，对着"+victim->query("name")+"射去！可惜偏了一点，射到了旁边的树上！\n"
                        +victim->query("name")+"发现了身边的危险，一下子窜到树丛中，消失的无影无踪。\n"NOR);
                }//end of switch
                message_vision(YEL"到手的猎物溜走了，$N懊恼得用手直拍自己的脑门！\n"NOR,me);
                return 1;
        }
        message_vision(HIM"$N张弓搭箭，正好射中了毫无防备的"+victim->query("name")+HIB"！\n"NOR,me);
        message_vision(HIM"$N兴高采烈的跑上前去捉住了受伤倒地的"+victim->query("name")+HIB"！\n"NOR,me);
        victim->move(me);
        me->add("combat_exp",(int)victim->query("dex")*5/2);
        me->add("potential",(int)victim->query("dex"));
        me->improve_skill("dodge", (int)victim->query("dex")/3);
        return 1;
}

