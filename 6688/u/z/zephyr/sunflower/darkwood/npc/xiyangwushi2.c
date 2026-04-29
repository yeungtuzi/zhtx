//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name("耶里华", ({ "yeli hua","wushi"}) );
	set("long",BLK@LONG
卷曲的头发和深陷的眼窝，显然不是中土人士。
他穿着一身纱织的衣衫，样子让人忍俊不禁，因
为中土只有女子才穿这种衣服。
LONG NOR
	 );

	set("title",BLK"西洋武士"NOR);
	set("age", 23);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("force",t+random(10));
	set_skill("jiuyang-shengong", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("xianyun", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("sword", t+random(10));
	set_skill("shenghuo-shengong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("qiankun-danuoyi",220);
	map_skill("iron-cloth", "jiuyang-shengong");
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "xianyun");
	map_skill("move", "xianyun");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-shengong");
       

	setup();
	set_skill("qiankun-danuoyi", 220);
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
	set("weapon_type","sword");
}                          

int killed_enemy(object ob)
{
	command("say 几里屋互利挂绿！");
}                 
