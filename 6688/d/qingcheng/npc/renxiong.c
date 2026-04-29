/*hourenxiong.c*/
inherit NPC;
void create()
{
        set_name("侯人雄",( {"hou renxiong","renxiong","hou"} ) );
        set("gender", "男性" );
        set("age", 25);
        set("str", 20);
        set("cor", 25);
        set("cps", 25);
	set("shen_type",-1);
      
        set("max_force", 200);
        set("force", 300);
        set("force_factor", 50);

       
        set("long",@LONG
 他是余沧海的嫡传弟子,是青城派年轻一代的高手,乃是青城四秀老二.
LONG);

       

        set("combat_exp", 400000);
        

        set("chat_chance_combat", 60);

        set_skill("unarmed", 60);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("sword", 80);
        set_skill("force", 20);

        set_skill("qingcheng-steps", 40);
        set_skill("cuixin-zhang",50);
        set_skill("pine-sword", 60);
        set_skill("qingcheng-force",20);

       create_family("青城派", 19, "弟子");

      map_skill("sword", "pine-sword");
      map_skill("dodge", "qingcheng-steps");
      map_skill("parry", "pine-sword");     
      map_skill("unarmed","cuixin-zhang");
      map_skill("force","qingcheng-force");
 
        setup();
        add_money("silver", 8);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

