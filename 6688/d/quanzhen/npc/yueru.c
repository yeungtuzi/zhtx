//hacky.c
//made by kiss or hacky

#include <ansi.h>
inherit F_MASTER;
inherit NPC;
inherit F_DEALER;
void create()
{

 set_name("点点",({"dian dian","dian"}));
 set("title",HIB"全真派"NOR+YEL"道童"NOR);
 set("nickname",RED"全真教知客总管"NOR);
 set("long","点点本是这个mud的神仙,不知为何现在改投了全真派,\n"
   "当上了全真派的公关部主管.\n"
      );
 set("rank_info/respect","帅哥");
 set("age",23);
 set("max_force",2000);
 set("force",2000);
 set("max_kee",1000);
 set("kee",1000);

 set("combat_exp",20000);
 set("attitude","friendly");

 set("int",30);
 set("str",20);
 set("con",25);

 set_skill("parry",25);
 set_skill("cuff",25);
 set_skill("dodge",30);
 set_skill("kongming-quan",30);
 set_skill("fx-step",30);
 set_skill("force",100);
 set_skill("xiantian-gong",100);

 map_skill("cuff","kongming-quan");
 map_skill("dodge","fx-step");
  map_skill("force","xiantian-gong");
 map_skill("parry","kongming-quan");

 set("chat_chance",10);
  set("chat_msg",({
  YEL"点点嫣然一笑:来拜全真教吧,如今全真如此兴旺,多少人想加入我们都不收呢!\n"NOR,
  YEL"点点偷偷告诉你:拜全真可是有很多好处的哦!\n"NOR,
  YEL"点点看着你,笑道:看你的样子,你怎么这么苯啊!\n"NOR,
  }));

 set("env/wimpy",10);

 set_temp("apply/attacka",20);
 set_temp("apply/defense",30);
 set_temp("apply/damage",30);

 set("vendor_goods",({
    __DIR__"obj/qz-map.c",
    __DIR__"obj/xiang",
   }));
 
 setup();

 add_money("gold",3);
}

void init()
{
  object ob;
  
  ob=this_player();
 
  ::init();
  remove_call_out("greeting");
  call_out("greeting",1,ob);
  add_action("do_list","list");
  add_action("do_buy","buy");
}

void greeting(object ob)
{
  if(!ob||environment(ob)!=environment() )  return;
  switch(random(3)) {
   case 0 : say("点点说:欢迎光临全真派,不知这位"+RANK_D->query_respect(ob)+"是来拜师还是烧香?\n");
     break;
   case 1 : say("点点笑说:这位"+RANK_D->query_respect(ob)+"买些香吧,保你一生不被人pk\n");
     break;
   case 2 : say("点点告诉你:全真派可是很大的哦,我这儿有全真派的地图,买一张吧.\n");
     break;
}
}

int accept_fight(object me)
{
  command("say"+me->query("name")+", 你发了什么病,干什么要打我?\n");
  command("chat 小女子今天跟你拼了!\n");
  command("cry");
  kill_ob(me);
  return 1;
 } 

void attempt_apprentice(object ob)
{
  command("say 呦,你要拜我啊,师傅还没有让我收徒呢!\n");
  command("sorry"+ob->query("id"));
  return;
}
