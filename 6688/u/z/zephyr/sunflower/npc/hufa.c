//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/guardnpc";
void create()
{
	int lvl,t,i,wea,gen;
	//随机生成等级
	lvl=random(8)+4;
	//随机生成武器类型
	wea=random(10);
	//性别
	gen=random(2);

	set("title",WHT"葵花宫护法"NOR);
	
	if (lvl>6)
	{
		if (random(100)>70)
		{
			lvl=5;
		}
		else lvl=6;
	}
	set("level",lvl);

	if (lvl==4) 
	{
		switch (wea)
		{
		case 0: set_name(YEL"剑奴"NOR, ({ "jian nu", "hufa"}) ); break;
		case 1: set_name(YEL"刀奴"NOR, ({ "dao nu", "hufa"}) ); break;
		case 2: set_name(YEL"枪奴"NOR, ({ "qiang nu", "hufa"}) ); break;
		case 3: set_name(YEL"叉奴"NOR, ({ "cha nu", "hufa"}) ); break;
		case 4: set_name(YEL"戟奴"NOR, ({ "ji nu", "hufa"}) ); break;
		case 5: set_name(YEL"杖奴"NOR, ({ "zhang nu", "hufa"}) ); break;
		case 6: set_name(YEL"斧奴"NOR, ({ "fu nu", "hufa"}) ); break;
		case 7: set_name(YEL"掌奴"NOR, ({ "zhang nu", "hufa"}) ); break;
		case 8: set_name(YEL"拳奴"NOR, ({ "quan nu", "hufa"}) ); break;
		case 9: set_name(YEL"鞭奴"NOR, ({ "bian nu", "hufa"}) ); break;
		}
	}

	else if (lvl==5)
	{
		switch (wea)
		{
		case 0: set_name(GRN"剑奴"NOR, ({ "jian nu", "hufa"}) ); break;
		case 1: set_name(GRN"刀奴"NOR, ({ "dao nu", "hufa"}) ); break;
		case 2: set_name(GRN"枪奴"NOR, ({ "qiang nu", "hufa"}) ); break;
		case 3: set_name(GRN"叉奴"NOR, ({ "cha nu", "hufa"}) ); break;
		case 4: set_name(GRN"戟奴"NOR, ({ "ji nu", "hufa"}) ); break;
		case 5: set_name(GRN"杖奴"NOR, ({ "zhang nu", "hufa"}) ); break;
		case 6: set_name(GRN"斧奴"NOR, ({ "fu nu", "hufa"}) ); break;
		case 7: set_name(GRN"掌奴"NOR, ({ "zhang nu", "hufa"}) ); break;
		case 8: set_name(GRN"拳奴"NOR, ({ "quan nu", "hufa"}) );break;
		case 9: set_name(GRN"鞭奴"NOR, ({ "bian nu", "hufa"}) ); break;
		}
	}
	else if (lvl==6)
	{
		switch (wea)
		{
		case 0: set_name(RED"剑奴"NOR, ({ "jian nu", "hufa"}) ); break;
		case 1: set_name(RED"刀奴"NOR, ({ "dao nu", "hufa"}) ); break;
		case 2: set_name(RED"枪奴"NOR, ({ "qiang nu", "hufa"}) ); break;
		case 3: set_name(RED"叉奴"NOR, ({ "cha nu", "hufa"}) ); break;
		case 4: set_name(RED"戟奴"NOR, ({ "ji nu", "hufa"}) ); break;
		case 5: set_name(RED"杖奴"NOR, ({ "zhang nu", "hufa"}) ); break;
		case 6: set_name(RED"斧奴"NOR, ({ "fu nu", "hufa"}) ); break;
		case 7: set_name(RED"掌奴"NOR, ({ "zhang nu", "hufa"}) ); break;
		case 8: set_name(RED"拳奴"NOR, ({ "quan nu", "hufa"}) ); break;
		case 9: set_name(RED"鞭奴"NOR, ({ "bian nu", "hufa"}) ); break;
		}
	}
	switch (gen)
	{
	case 1:	
set("long",WHT@LONG
这是一个翩翩美少年，剑眉星目。传说葵花宫收养了一些孤儿，并传
他们武艺，看来此言非虚，看此子虽然年龄甚小，但是气若沉渊，俨
然已具高手风范，不可小觑。
LONG NOR
);
			set("gender", "男性");
			break;
	case 0:	
set("long",MAG@LONG
这是一个窈窕美少女，眸若晨星，眉似弯月。传说葵花宫收养了一些孤
儿，并传他们武艺，看来此言非虚，看此女虽然年龄甚小，但是气若沉
渊，俨然已具高手风范，不可小觑。
LONG NOR
);
			set("gender","女性");
			break;
	}
	
	set("age", 18);
	set("per", 99);

	//set advanced skills
	t=230+(6-lvl)*25;


	set_skill("force", t+random(10));
	set_skill("taiji-shengong", t+random(10));
	set_skill("huntian-qigong", t+random(10));
	set_skill("zixia-shengong", t+random(10));
	set_skill("iceforce", t+random(10));
	set_skill("jiuyang-shengong", t+random(10));
	set_skill("xiantian-gong", t+random(10));

	set_skill("iron-cloth", t+random(10));

	set_skill("dodge", t+random(10));
	set_skill("stormdance", t+random(10));
	set_skill("bat-steps", t+random(10));
	set_skill("baguabu", t+random(10));
	set_skill("tiyunzong", t+random(10));
	set_skill("yueying-wubu", t+random(10));
	set_skill("notracesnow", t+random(10));
	set_skill("zhutian", t+random(10));
	set_skill("fall-steps", t+random(10));
	set_skill("fx-step", t+random(10));

	set_skill("cuff", t+random(10));
	set_skill("jingang-quan",t+random(10));
	set_skill("ill-quan",t+random(10));
	set_skill("kongming-quan",t+random(10));
	set_skill("yangxin-quan",t+random(10));
	set_skill("taiji-quan", t+random(10));
	set_skill("qishang-quan", t+random(10));
	
	set_skill("claw", t+random(10));
	set_skill("spicyclaw", t+random(10));
	set_skill("sougu", t+random(10));

	set_skill("strike", t+random(10));
	set_skill("bloodystrike", t+random(10));
	set_skill("xianglong-zhang", t+random(10));
	set_skill("xingxiu-duzhang", t+random(10));
	set_skill("meihua-shou", t+random(10));
	set_skill("sanhua-zhang", t+random(10));
	
	set_skill("sword", t+random(10));
	set_skill("dugu-jiujian", t+random(10));
	set_skill("pixie-sword", t+random(10));
	set_skill("taiji-jian", t+random(10));
	set_skill("six-chaos-sword", t+random(10));
	set_skill("mo-jian-jue", t+random(10));
	set_skill("divine-mystsword", t+random(10));
	set_skill("tonggui-jian", t+random(10));

	set_skill("blade", t+random(10));
	set_skill("yanxing-dao", t+random(10));
	set_skill("mo-dao-jue", t+random(10));
	set_skill("shortsong-blade", t+random(10));
	set_skill("spring-blade", t+random(10));
	set_skill("spring-blade", t+random(10));
	set_skill("liuhe-dao", t+random(10));

	set_skill("spear", t+random(10));
	set_skill("mo-qiang-jue", t+random(10));
	set_skill("yangjia-qiang", t+random(10));


	set_skill("fork", t+random(10));
	set_skill("mo-cha-jue", t+random(10));

	set_skill("whip", t+random(10));
	set_skill("mo-bian-jue", t+random(10));
	set_skill("snowwhip", t+random(10));
	set_skill("riyue-bian", t+random(10));


	set_skill("staff", t+random(10));
	set_skill("dagou-bang", t+random(10));
	set_skill("cloudstaff", t+random(10));
	set_skill("wuchang-zhang", t+random(10));
	set_skill("zui-gun", t+random(10));
	set_skill("weituo-gun", t+random(10));

	set_skill("halberd", t+random(10));
	set_skill("mo-ji-jue", t+random(10));


	set_skill("parry", t+random(10));
	set_skill("perception", t+random(10));




//随机初始化功夫map
//首先选择一种内力
	i=random(8);
	if (i>=5) 	{map_skill("force","zixia-shengong");set("percmd","exert powerup");}
	if (i==4) 	{map_skill("force","xiantian-gong");set("percmd","exert powerup");;map_skill("iron-cloth","xiantian-gong");}
	if (i==3) 	{map_skill("force","jiuyang-shengong");map_skill("iron-cloth","jiuyang-shengong");}
	if (i==2) 	map_skill("force","taiji-shengong");
	if (i==1) 	map_skill("force","huntian-qigong");
	if (i==0) 	{map_skill("force","iceforce");set("percmd","exert chillgaze");}
//选定一种轻功
	i=random(9);
	if (i==8) 	{map_skill("dodge","fx-step");	map_skill("move","fx-step");}
	if (i==7) 	{map_skill("dodge","fall-steps");	map_skill("move","fall-steps");}
	if (i==6) 	{map_skill("dodge","zhutian");	map_skill("move","zhutian");}
	if (i==5) 	{map_skill("dodge","notracesnow");	map_skill("move","notracesnow");}
	if (i==4) 	{map_skill("dodge","yueying-wubu");	map_skill("move","yueying-wubu");}
	if (i==3) 	{map_skill("dodge","stormdance");	map_skill("move","stormdance");}
	if (i==2) 	{map_skill("dodge","bat-steps");	map_skill("move","bat-steps");}
	if (i==1) 	{map_skill("dodge","tiyunzong");	map_skill("move","tiyunzong");}
	if (i==0) 	{map_skill("dodge","baguabu");	map_skill("move","baguabu");}
//选择一种sword
	i=random(7);
	if (i==6) 	map_skill("sword","tonggui-jian");
	if (i==5) 	map_skill("sword","mo-jian-jue");
	if (i==4) 	map_skill("sword","divine-mystsword");
	if (i==3) 	map_skill("sword","pixie-sword");
	if (i==2) 	map_skill("sword","dugu-jiujian");
	if (i==1) 	map_skill("sword","taiji-jian");
	if (i==0) 	map_skill("sword","six-chaos-sword");
//选择一种blade
	i=random(6);
	if (i==5) 	map_skill("blade","yanxing-dao");
	if (i==4) 	map_skill("blade","mo-dao-jue");
	if (i==3) 	map_skill("blade","spring-blade");
	if (i==2) 	map_skill("blade","liuhe-dao");
	if (i==1) 	{map_skill("blade","spring-blade");	set("skill_mark/spring-blade",1);}
	if (i==0) 	map_skill("blade","shortsong-blade");
//选择一种spear
	i=random(2);
	if (i==1) 	map_skill("spear","mo-qiang-jue");
	if (i==0) 	map_skill("spear","yangjia-qiang");
//选择一种fork
 	map_skill("fork","mo-cha-jue");
//选择一种whip
	i=random(3);
	if (i==2) 	map_skill("whip","mo-bian-jue");
	if (i==1) 	map_skill("whip","snowwhip");
	if (i==0) 	map_skill("whip","riyue-bian");
//选择一种ji
	map_skill("halberd","mo-ji-jue");
//选择一种staff
	i=random(5);
	if (i==4) 	map_skill("staff","dagou-bang");
	if (i==3) 	map_skill("staff","zui-gun");
	if (i==2) 	map_skill("staff","cloudstaff");
	if (i==1) 	map_skill("staff","weituo-gun");
	if (i==0) 	map_skill("staff","wuchang-zhangfa");
//选择一种axe
	map_skill("axe","mo-fu-jue");
//选择一种whip
	i=random(6);
	if (i==5) 	map_skill("sword","mo-jian-jue");
	if (i==4) 	map_skill("sword","divine-mystsword");
	if (i==3) 	map_skill("sword","pixie-sword");
	if (i==2) 	map_skill("sword","dugu-jiujian");
	if (i==1) 	map_skill("sword","taiji-jian");
	if (i==0) 	map_skill("sword","six-chaos-sword");
//选择一种招架

	if (random(100)>10) 	map_skill("parry","taiji-jian");
	else	map_skill("parry","qiankun-danuoyi");
//现在来决定用空手还是用一种兵器
		switch (wea)
		{
		case 0: 		carry_object("/obj/weapon/sword")->wield();
						set("weapon_type","sword"); 
						break;
		case 1: 		carry_object("/obj/weapon/blade")->wield();
						set("weapon_type","blade"); 
						break;
		case 2: 		carry_object("/obj/weapon/spear")->wield();
						set("weapon_type","spear"); 
						break;
		case 3: 		carry_object("/obj/weapon/fork")->wield();
						set("weapon_type","fork"); 
						break;
		case 4: 		carry_object("/obj/weapon/fangtianji")->wield();
						set("weapon_type","fangtianji"); 
						break;
		case 5: 		carry_object("/d/hudie/obj/dragon-staff")->wield();
						set("weapon_type","staff"); 
						break;
		case 6: 		carry_object("/obj/weapon/axe")->wield();
						set("weapon_type","axe"); 
						break;
		case 7: 		i=random(7);
						if (i==6) 	{map_skill("strike","xianglong-zhang");prepare_skill("strike","xianglong-zhang");}
						if (i==5) 	{map_skill("strike","xingxiu-duzhang");prepare_skill("strike","xianglong-zhang");}
						if (i==4) 	{map_skill("strike","sanhua-zhang");prepare_skill("strike","sanhua-zhang");}
						if (i==3) 	{map_skill("strike","bloodystrike");prepare_skill("strike","bloodystrike");}
						if (i==2) 	{map_skill("strike","meihua-shou");prepare_skill("strike","meihua-shou");}
						if (i==1) 	{map_skill("claw","yingzhao-qinnanshou");prepare_skill("claw","yingzhao-qinnanshou");}
						if (i==0) 	{map_skill("claw","spicyclaw");prepare_skill("claw","spicyclaw");}
						break;
		case 8: 		i=random(6);
						if (i==5) 	{map_skill("cuff","taiji-quan");prepare_skill("cuff","taiji-quan");}
						if (i==4) 	{map_skill("cuff","jingang-quan");prepare_skill("cuff","jingang-quan");}
						if (i==3) 	{map_skill("cuff","ill-quan");prepare_skill("cuff","ill-quan");}
						if (i==2) 	{map_skill("cuff","kongming-quan");prepare_skill("cuff","kongming-quan");}
						if (i==1) 	{map_skill("cuff","yangxin-quan");prepare_skill("cuff","yangxin-quan");}
						if (i==0) 	{map_skill("cuff","qishang-quan");prepare_skill("cuff","qishang-quan");}
						break;
		case 9: 		carry_object("/obj/weapon/whip")->wield();
						set("weapon_type","whip"); 
						break;
		}

	setup();
	carry_object("/obj/cloth/cloth")->wear();

}                          
                     
