//redshiwei.c
//by tlang

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
	
        set_name(name, ({ id, "shiwei" }) );
	set("gender", "男性");
        set("title",HIR "宁王府"NOR + BLU "紫衣" NOR +"侍卫");
        set("nickname", nick);

	set("long",
		"这人一脸严肃，令人望而生畏，但给人一种正直的感觉。\n");
	set("combat_exp", 500000+random(100000));
        set("shen_type", 2);
	set("attitude", "heroism");
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(HIY "为国为民，侠之大者!\n" NOR),
		(HIG "功夫不仅是练出来的，还需要你去思考!\n" NOR),
        }) );


	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("mo-shan-jue",100);
        map_skill("dodge","mo-shan-jue");   

        create_family("宁王府", 2, "侍卫");


	setup();
        
	if(strsrch(nick,"剑")!=-1)
	 {
          carry_object("/d/heimuya/obj/sword")->wield();
	  set_skill("sword",100);
	  set_skill("mo-jian-jue",100);
	  map_skill("sword","mo-jian-jue");
	  map_skill("parry","mo-jian-jue");   
	  
	 }	
        else if(strsrch(nick,"刀")!=-1)
	 {
          carry_object("/d/heimuya/obj/blade")->wield();
	  set_skill("blade",100);
          set_skill("mo-dao-jue",100);
          map_skill("blade","mo-dao-jue");
	  map_skill("parry","mo-dao-jue");
	 }
        else if(strsrch(nick,"钩")!=-1)
	 {
	  carry_object("/d/heimuya/obj/gou")->wield();
          set_skill("gou",100);
          set_skill("mo-gou-jue",100);
          map_skill("gou","mo-gou-jue");
	  map_skill("parry","mo-gou-jue");
         }
        else if(strsrch(nick,"戟")!=-1)
	 {
	  carry_object("/d/heimuya/obj/ji")->wield();
          set_skill("ji",100);
          set_skill("mo-ji-jue",100);
          map_skill("ji","mo-ji-jue");
	  map_skill("parry","mo-ji-jue");
         }
        else if(strsrch(nick,"锤")!=-1)
	 {
	 carry_object("/d/heimuya/obj/hammer")->wield();
	 set_skill("hammer",100);
         set_skill("mo-chui-jue",100);   
         map_skill("hammer","mo-chui-jue");
	 map_skill("parry","mo-chui-jue");
         }

        else if(strsrch(nick,"斧")!=-1)
	 {
	  carry_object("/d/heimuya/obj/axe")->wield();
          set_skill("axe",100);
          set_skill("mo-fu-jue",100);
          map_skill("axe","mo-fu-jue");
	  map_skill("parry","mo-fu-jue");
         }
        else if(strsrch(nick,"叉")!=-1)
	 {
         carry_object("/d/heimuya/obj/fork")->wield();
         set_skill("fork",100);
         set_skill("mo-cha-jue",100);   
         map_skill("fork","mo-cha-jue");
	 map_skill("parry","mo-cha-jue");
         }

        else if(strsrch(nick,"枪")!=-1)
	 {
          carry_object("/d/heimuya/obj/qiang")->wield();
          set_skill("qiang",100);
          set_skill("mo-qiang-jue",100);
          map_skill("qian","mo-qiang-jue");
 	  map_skill("parry","mo-qiang-jue");
         }
        else if(strsrch(nick,"鞭")!=-1)
	 {
          carry_object("/d/heimuya/obj/whip")->wield();
	  set_skill("whip",100);
          set_skill("mo-bian-jue",100);
          map_skill("whip","mo-bian-jue");
	  map_skill("parry","mo-bian-jue");
         }
	else 
	 {
  	  set_skill("mo-zhang-jue",100);
          map_skill("unarmed","mo-zhang-jue");
	 }

        carry_object("/obj/cloth")->wear();
	add_money("silver", 10);
}

int accept_fight()
{
	command("say 恭敬不如从命.\n");
	command("smile");
		return 1;
}
int accept_kill(object killer)
{
 	int i;
	object *ob,me;
	me=this_object();
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="宁王府") continue;
		if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
		write(ob[i]->query("name")+ "吼道:"+HIY 
                "好小子, 居然敢杀我们宁王府的人,死去吧你!\n" NOR);
        }
        return 1;
}

void kailiu()
{
	int i;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                if( enemy[i]->query("combat_exp")<= query("combat_exp")) {
		            set_leader(enemy[i]);
			    kill_ob(enemy[i]);
                            break;
                        }
		else
		  {
		    command("say 点子扎手!!!扯呼!!!");
                    set("env/wimpy", 80);
		    kill_ob(enemy[i]);	
		    random_move();
		    add("is_here",1);
		   }
                }
}




