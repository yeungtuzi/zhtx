/*jirenying.c*/
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("吉人英", ({"ji renying","renying","ji"})  );
        set("gender", "男性" );
        set("age", 30);
        set("str", 25);
        set("cor", 20);
        set("cps", 28);
	set("shen_type",-1);
      
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 10);

       
        set("long",@LONG
 他是余沧海的大弟子,一身功夫尽得余沧海的真传,青城派年轻一代佼佼者,
为青城四秀之首.
LONG);

       

        set("combat_exp", 500000);
        

        set("chat_chance_combat", 60);

        set_skill("strike", 80);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("sword", 90);
        set_skill("force", 40);

        set_skill("qingcheng-steps", 50);
        set_skill("cuixin-zhang",80);
        set_skill("pine-sword", 80);
        set_skill("qingcheng-force",40);

       create_family("青城派", 19, "弟子");

      map_skill("sword", "pine-sword");
      map_skill("dodge", "qingcheng-steps");
      map_skill("parry", "pine-sword");     
      map_skill("strike","cuixin-zhang");
      map_skill("force","qingcheng-force");
      prepare_skill("strike","cuixin-zhang");

 
        setup();
        add_money("silver", 8);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

void reset()
{
        delete_temp("learned");
}

void attempt_apprentice(object ob)
{
   command( "recruit " + ob->query("id") );
}
 

 
