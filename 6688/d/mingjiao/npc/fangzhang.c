// fangzhang.c 方丈
#include <ansi.h>
#include <localtime.h>
inherit NPC;
int check_moon();
int ask_zhi();
int ask_du();
int ask_baozi();
int ask_learn();
int check(object me);
void create()
{
        set_name("方丈", ({ "fang zhang", "zhang" }));
        set("long",
                "他就是化生寺方丈，是佛教的泰山北斗，精研佛法，比\n"
                "少林的圣僧们还要精通佛法。身穿一件污秽的僧袍。\n"
                "双手合在胸前，似乎少了两个手指。\n");
        set("gender", "男性");
        set("age", 80);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_kee", 5000);
        set("max_gin", 3000);
        set("max_sen", 300);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
        set("combat_exp", 50000);
        set("score", 500000);
        set("inquiry",([
               "八指"  : (: ask_zhi :),
               "赌博"  : (: ask_du :),
               "豹子"  : (: ask_baozi :),
           "学投豹子"  : (: ask_learn :),
        ]));


        set_skill("literate", 200);
        set_skill("buddhism", 200);
        setup();

}


void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !random(5) ) {
                remove_call_out("greeting");
                call_out("greeting", 5, ob);
        }

}

void greeting(object ob)
{
        say("方丈说:“百善孝为先，万恶淫为首“\n");
        if( !ob || environment(ob) != environment() ) return;
        if (!check_moon()) return;
        say ("方丈说：”其实赌博才是万恶之首。“\n");
}


int ask_du()
{
 if( check_moon()) {say ("方丈说：想当年，老衲出家前，在赌场号称”豹子王“\n");
                    say ("方丈叹了口气：可是后来...不提了。\n");
                    this_player()->set_temp("ask_du",1);

                        }
 else    say ("方丈有些神色黯然。\n");

 return 1;
}
int ask_zhi()
{
if(!(int)this_player()->query_temp("ask_du")) return 0;
say ("方丈说:老衲就是被此地赌场的大管家赢去两条手指的。\n");
this_player()->set_temp("canlearn-baozi",1);
return 1;

}

int ask_baozi()
{
if (!(int)this_player()->query_temp("canlearn-baozi")) return 0;
say ("方丈说: 豹子就是把三个骰子都投成六。\n");
say ("方丈说: 学投豹子需要”象牙骰子“和熟练的手法。\n");
this_player()->set_temp("baozi",1);
return 1;
}

int ask_learn()
{
if (!(int)this_player()->query_temp("baozi")) return 0;
if (!check(this_player()))
{
write ("方丈说:你学不了豹子\n");
return 0;
}
this_player()->set("baozi",1);
say ("方丈说: 好，老衲教你学投豹子。\n");
say ("你似乎学会了一点，应该去和大管家赌一场。\n");
return 1;
}

#define TIME_TICK (time()*60)
int check_moon() {
  mixed *local;
  int data,hour;

  local = localtime(TIME_TICK);
  printf("%d/%d/%d/%d\n",local[LT_YEAR],local[LT_MON],local[LT_MDAY],local[LT_HOUR]);
  data = local[LT_MDAY];
  if( data >15) return 0;
  hour =  local[LT_HOUR];
  if( hour > 10 && hour < 15 ) return 0;
 data = local[LT_MDAY];
  if( data >15) return 0;
  hour =  local[LT_HOUR];
  if( hour > 10 && hour < 15 ) return 0;

  return 1;
}

int check(object me)
{

if( !objectp(present("dice", me)) )
{write ("你身上没有骰子这样东西。\n");
 return 0;
}

 me->start_busy(1);

return 1;


}
