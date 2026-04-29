// Created by hacky
// data: 1997.10.10
               
#include <ansi.h> 
inherit NPC; 
inherit F_MASTER;
   

void create()
{
	set_name("郝大通", ({ "hao datong" , "hao" }));
	set("nickname", HIB"广宁子"NOR);
        set("title",HIB"全真派"NOR+GRN"真人"NOR);
/*	set("long",@LONG
他就是全真教第二代弟子广宁子郝大通,
            LONG
           );     
  */
	set("gender", "男性");
	set("age", 59);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 27);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_kee", 1500);
	set("max_gin", 1500);
	set("force", 2500);
	set("max_force", 2500);
	set("enforce", 100);
	set("combat_exp", 175000);
	set("score", 10000);
	set_skill("taoism",100);
	set_skill("sword",110);
        set_skill("quanzhen-jian",100);
	set_skill("array", 80);
	set_skill("dodge", 100);
	set_skill("fx-step", 120);
	set_skill("unarmed", 120);
	set_skill("parry", 120);
        map_skill("sword","quanzhen-jian");
	map_skill("dodge","fx-step");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);

	setup();
       
	create_family("全真派", 2, "真人");
	carry_object(__DIR__"obj/robe")->wear();

}


void attempt_apprentice(object ob)
  
{
  command("say 现在我不收弟子!");
  return;     
}
