//daoshi.c
//made by hacky
inherit NPC;
#include <ansi.h>
#include "/u/hacky/random_name.h"
void create ()
{
  string name;
  name=get_rndname();
 set_name(name,({"daoshi","dao","shi"}));
 set("long",@LONG
他是全真教的烧火的小道童.
LONG
    );
 set("title",HIB"全真派"NOR+YEL"烧火小道士"NOR);
 set("gender","男性");
 set("age",17);
 set("attitude","peaceful");
 set("shen_type",0+random(1000));
  set("str",20);
  set("int",25);
  set("con",20);
  set("combat_exp",2000+random(1000));
  set("score",1000+random(500));
  set("max_neili",200+random(100));
  set("neili",200+random(100));
  set_skill("force",20+random(11));
  set_skill("parry",15+random(10));
  set_skill("dodge",20+random(10));
  set_skill("unarmed",25+random(10));
  set_temp("parry/attack",17+random(5));
  set_temp("parry/damage",5+random(10));
  set_temp("parry/defense",20+random(5));
  create_family("全真教",5,"弟子");
  setup();
 }
