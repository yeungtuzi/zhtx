//made by hacky;
//97,11,27
#include <ansi.h>
inherit NPC;
string ask_yao();
void create()
{
     set_name("老者",({"lao zhe","lao"}));
     set("nickname",HIC"园圃管家"NOR);
     set("long",@LONG
他就是全真教负责照看园圃的人,
LONG
     );
     set("age",56);
     set("attitude","peaceful");
     set("score",10000);
     set("shen_type",1);

     set("max_neili",500);
     set("neili",500);
     set("combat_exp",5000);

     set_skill("parry",30);
     set_skill("dodge",30);
     set_skill("cuff",30);
     set_temp("apply/dodge",30);
     set_temp("apply/parry",30);
     set_temp("apply/defence",30);

     set("chat_chance",10);
     set("chat_msg",({
 "老者哈哈大笑:这些植物如今能生长的如此好,全是我的功劳啊!\n",
     }));

      set("yao_count",3);
     set("inquiry",([
          "药" : (: ask_yao : ),
       ]));
      setup();

     carry_object(__DIR__"obj/jiandao.c");


  }
 
void init()
{
     object me;
     ::init();
     if(interactive(me=this_player())&&!is_fighting() )
     {
      remove_call_out("greeting");
      call_out("greeting",3,me);
      return;
      }
}

void greeting(object me)
{
   object ob=this_object();
   command("smile"+ob->query("id"));
   message_vision("$N笑着对$n说:这位"+RANK_D->query_respect(me)+"来看看我的园圃吧\n",ob,me);
}

string ask_yao()
{
   object obj;
   object ob=this_player();
   if(ob->query("family/family_name")!="全真派")
   
    return HIB"你与我全真素无瓜葛,这话如何说起?\n"NOR;
    
   
   if(query("yao_count")<1)
   
    return YEL" 哟,我现在身上已经没有药了\n"NOR;
   if((int)ob->query("eff_qi")==(int)ob->query("max_qi"))
   
    return RED"我看你血气充盈,似乎并没有受伤,为何找我问药?\n"NOR;
    
   
   if((int)ob->query_temp("have_yao"))
   
   return HIW"刚才你不是给你药了么？ 你真是贪得无厌!!\n"NOR;
   
   add("yao_count",-1);
   ob->set_temp("have_yao",1);
   obj=new(__DIR__"obj/gao.c");
   obj->move(ob);
   return YEL"我看你似乎受了些伤,这里有些伤药,给你吧\n"NOR;
}
