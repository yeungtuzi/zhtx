#include <ansi.h>
#include <armor.h>  
inherit NECK;

int wear()
{
	if( !this_player()->query("bingqipu_success") )
		return notify_fail("这册兵器谱不是兵器贩子给你的，擅自使用会受到他的惩罚！\n");
	if (this_player()->query("combat_exp")<8000000)
		return notify_fail("以你的能力，恐怕这册兵器谱是别人帮你搞到的吧？？混点武林声望就罢了，还想怎么样？！\n");
	return ::wear();
}

//随身
string query_autoload()
{
        return query("name");
}

void autoload(string arg)
{
 set("name",arg);
}


//不让丢、卖、当、给别人
void init()
{               
	object me;

	me=this_player();
	if (!wizardp(me)) {
		set("unpawnable",1);
		set("no_get", name()+"只跟随他选定的主人！ \n");
		set("no_put", "此乃武林至宝，不可到处乱放！ \n");
		set("no_paimai", "拿去拍卖，被邪魔外道买了去怎么办！ \n");
		set("no_drop","武林至宝，怎可随意乱丢！ \n");
		set("no_give","兵器谱不可随意送人，如果落入邪魔之手，生灵涂炭！");
		set("no_sell","兵器谱乃宝物，店铺不敢收取！");
	}
	add_action("do_feel","feel");
}

void owner_is_killed() 
{ 
        object me,ob;
        ob = this_object();
        //me = ob->query("owner");
        //if(!userp(me)) return 0;
        //message("system",MAG"\n【世外逸仙】兵器贩子(Weaponor)：唉！\n"NOR,users() );
        message("system",HIW"\n七修剑化作一道银色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        message("system",HIM"\n斩铁剑化作一道紫色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        message("system",HIY"\n出跸刀化作一道黄色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        message("system",HIB"\n温柔化作一道蓝色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        message("system",HIC"\n破残化作一道青色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        message("system",HIR"\n灵空剑化作一道红色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        message("system",HIG"\n刈鹿刀化作一道绿色的光芒冲上云霄渐渐消失不见。\n"NOR,users() );
        destruct(this_object());
}

