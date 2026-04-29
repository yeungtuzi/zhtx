/*弟子*/
inherit NPC;
void create()
{
        set_name("青城弟子", ({"dizi"})  );
        set("gender", "男性" );
        set("age", 20);
            
        set("long",@LONG
 他是青城弟子,正在这里接受训练,好早日成为一名及格的剑士.
LONG);

   
       set("combat_exp", 400);
        

        set("chat_chance_combat", 60);

        set_skill("unarmed", 10);
        set_skill("sword", 10);
       
       create_family("青城派", 20, "弟子");

     
        setup();
        add_money("coin", 50);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

