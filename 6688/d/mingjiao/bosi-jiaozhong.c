// jiao_zhong1.c
//write by dfbb@hero
//
#include <ansi.h>
inherit NPC;

#include <random_name.h>


void kailiu();

void create()
{
        string name,id,nick;

	name = get_rndname();
	id = get_rndid();
	nick = get_rndnick();
	
        set_name(name, ({ id, "jiaozhong" }) );
	set("gender", "男性");
        set("title",GRN"波斯明教"+NOR"教众");
        set("nickname", nick);

	set("age", random(50));
	set("long",
		"这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 150000+random(150000));
        set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed",70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("mo-shan-jue",70);
        map_skill("dodge","mo-shan-jue");   

	setup();
        
	if(strsrch(nick,"剑")!=-1)
	 {
          carry_object("/d/heimuya/obj/sword")->wield();
	  set_skill("sword",70);
	  set_skill("mo-jian-jue",70);
	  map_skill("sword","mo-jian-jue");
	  map_skill("parry","mo-jian-jue");   
	  
	 }	
        else if(strsrch(nick,"刀")!=-1)
	 {
          carry_object("/d/heimuya/obj/blade")->wield();
	  set_skill("blade",60);
          set_skill("mo-dao-jue",60);
          map_skill("blade","mo-dao-jue");
	  map_skill("parry","mo-dao-jue");
	 }
        else if(strsrch(nick,"钩")!=-1)
	 {
	  carry_object("/d/heimuya/obj/gou")->wield();
          set_skill("gou",70);
          set_skill("mo-gou-jue",70);
          map_skill("gou","mo-gou-jue");
	  map_skill("parry","mo-gou-jue");
         }
        else if(strsrch(nick,"戟")!=-1)
	 {
	  carry_object("/d/heimuya/obj/ji")->wield();
          set_skill("ji",70);
          set_skill("mo-ji-jue",70);
          map_skill("ji","mo-ji-jue");
	  map_skill("parry","mo-ji-jue");
         }
        else if(strsrch(nick,"锤")!=-1)
	 {
	 carry_object("/d/heimuya/obj/hammer")->wield();
	 set_skill("hammer",70);
         set_skill("mo-chui-jue",70);   
         map_skill("hammer","mo-chui-jue");
	 map_skill("parry","mo-chui-jue");
         }

        else if(strsrch(nick,"斧")!=-1)
	 {
	  carry_object("/d/heimuya/obj/axe")->wield();
          set_skill("axe",70);
          set_skill("mo-fu-jue",70);
          map_skill("axe","mo-fu-jue");
	  map_skill("parry","mo-fu-jue");
         }
        else if(strsrch(nick,"叉")!=-1)
	 {
         carry_object("/d/heimuya/obj/fork")->wield();
         set_skill("fork",70);
         set_skill("mo-cha-jue",70);   
         map_skill("fork","mo-cha-jue");
	 map_skill("parry","mo-cha-jue");
         }

        else if(strsrch(nick,"枪")!=-1)
	 {
	  carry_object("/d/heimuya/obj/qiang")->wield();
          set_skill("qiang",70);
          set_skill("mo-qiang-jue",70);
          map_skill("qian","mo-qiang-jue");
 	  map_skill("parry","mo-qiang-jue");
         }
        else if(strsrch(nick,"鞭")!=-1)
	 {
          carry_object("/d/heimuya/obj/whip")->wield();
	  set_skill("whip",70);
          set_skill("mo-bian-jue",70);
          map_skill("whip","mo-bian-jue");
	  map_skill("parry","mo-bian-jue");
         }
	else 
	 {
  	  set_skill("mo-zhang-jue",80);
          map_skill("unarmed","mo-zhang-jue");
	 }

        carry_object("/obj/cloth")->wear();
	add_money("silver", 10);
}


