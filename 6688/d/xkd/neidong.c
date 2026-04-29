#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIW"侠客岛内洞"NOR);
        set("long", @LONG
这是侠客岛的一间内洞，很多内功修为极高的前辈高手都在这里修炼，
你几乎听不到呼吸的声音，但却隐约可以感受到他们体内气息的流动，据说
只有在江湖中地位显赫、威震天下且又内功修为几近自身极限的人才有资格
在这里修炼。
LONG
        );
        set("no_fight",1);  
        set("no_poison",1);
        set("no_magic",1);  
        set("no_steal",1);
        set("no_death",1);
        set("no_get",1);
        set("no_faint",1);
        set("exits", ([
                "out" : __DIR__"shi3",
        ]));

        setup();
}

void init()
{       
        object ob = this_player();
/*
        if( (int)ob->query_condition("bonze_jail") <= 0 )
        {
                message("vision",
                        HIY "只听牢房铁门匡地一响，一个昏昏沉沉的家伙被扔了进来！\n\n" NOR, 
                        environment(ob), ob);

                tell_object(ob, "狱卒嘿嘿地笑着：今儿个你可落在我手里了...！\n");

                ob->set("startroom", "/d/wizard/jianyu");
                ob->apply_condition("bonze_jail", 60);
        }
*/
        add_action("do_anneal","anneal");
        add_action("do_go","go");
        add_action("do_summon","summon");
        add_action("do_chat","chat");
        add_action("do_chat","chat*");
        add_action("do_bid","bid");
        add_action("do_bid","new");
        add_action("do_bid","new*");
        add_action("do_chat","mp");
        add_action("do_pray","use");
        add_action("do_conjure","conjure");
        add_action("do_es","zh");
        add_action("do_es","zh*");
        add_action("do_rumor","rumor");
        add_action("do_rumor","rumor*");
        add_action("do_tell","tell");
        add_action("do_reply","reply");
        add_action("do_exercise","exercise");
        add_action("do_meditate","meditate");
        add_action("do_respirate","respirate");
        add_action("do_exert","exert");
        add_action("do_practice", "practice");
        add_action("do_study","study");
        add_action("do_cast","cast");
        add_action("do_fight","fight");
        add_action("do_hit","hit");
        add_action("do_kill","kill");
        add_action("do_steal","steal");
        add_action("do_pray","pray");
        add_action("do_scribe","scribe");
        add_action("do_burn","burn");
        add_action("do_attach","attach");
        add_action("do_vote","vote");
        add_action("do_music","music");
        add_action("do_music","music*");
        add_action("do_suicide","suicide");
        add_action("do_flyup","flyup");
        add_action("do_say","say");
        add_action("do_perform","perform");
        add_action("do_quit","quit");
}

int do_anneal(string arg)
{
       int wx;
       object me;
       me=this_player();

       wx = me->query("int");


//       if ( !arg || arg != "wall" )
//                return notify_fail("你要研读什么？\n");

       if ( !me->query("got_ling") )
                return notify_fail("你是怎么跑到侠客岛来的？\n");

       if( (int)me->query("wlshw") < 100 )
                return notify_fail("你在江湖中的声望不够，无法闭关修炼。\n");

       if ( me->query("max_force") < 8000 )
                return notify_fail("你的内力太低了，无法闭关修炼。\n");

       if ( me->query("combat_exp") < 40000000 )
                return notify_fail("你的江湖经验还不够老到，无法闭关修炼。\n");

       if ( me->query_skill("force", 1) < 400 )
                return notify_fail("你的内功修为太低，无法闭关修炼。\n");

       tell_object(me,HIW"你盘膝坐下，眼观鼻，鼻观口，口问心，逐渐进入物我两忘的境界。\n一时间皇图霸业，血海深仇，江湖纷争，刀光剑影皆尽归尘土。\n你渐感冥冥中有天人正在指引你向着无上武道而前行，\n而这条路则极为艰险波折，一不注意很有可能走火入魔。\n"NOR);

       me->apply_condition("super_ex", 5000);
       me->start_busy(5000);
       me->set_temp("start_ex", 1);
   
       call_out("finish_ex", 3600); 
       return 1;
}


int finish_ex()
{
       object me;
       me=this_player();

       if ( !me->query_temp("start_ex") ) return 0;

       tell_object(me,HIC"你定气凝神，将体内的真气收于丹田，经过这一段艰难痛苦的修炼，你的内功修为的确精进了不少。\n"NOR);
       me->clear_condition("super_ex");
       me->start_busy(1);
       me->set_skill("force", me->query_skill("force", 1) + 1);
       me->add("max_force", 8+random(8));
       me->add("wlshw", -100);
       me->add("combat_exp", -500000);
       return 1;
}


int do_bid(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR);
                return 1;
}

int do_conjure(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_chat(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_go(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_summon(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_es(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_rumor(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_tell(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_reply(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_exercise(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_meditate(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_respirate(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}
int do_exert(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_practice(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_study(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_cast(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_fight(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_hit(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_kill(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_steal(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_pray(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_scribe(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_burn(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_attach(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_vote(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_music(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

int do_suicide(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}
int do_flyup(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}
int do_say(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}
int do_perform(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}
int do_quit(string arg)
{
                if(this_player()->query_condition("super_ex") > 0)
                write( HIY"别忘了你正在闭关修炼，除了打坐你什么也干不了。\n\n" NOR); 
                return 1;
}

