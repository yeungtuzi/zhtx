// xianyun-shenfa 纤云身法
// written by dingdang, add by hacky
inherit SKILL;
string *dodge_msg = ({
	"却见$n展开轻功，向旁急退，避过了这一招。\n",
	"$n运起绝顶轻功，漫天飞舞，忽急忽慢，躲了开去。\n",
	"却见$n伏低身子向后一串，$N这一招扑了个空。\n",
        "$n双足点地，倏地一下从$N头顶掠过，如风拂玉树，雪裹琼苞，冷浸溶溶月。\n",
        "$n一个「比翼双飞」，随着$N的攻势飘起，从容躲过这一招。\n",
        "$n使出一招「巧燕穿云」，猛然纵起丈余，结果$N扑了个空。\n",
        "$n身形一摇，幻出几个人影，一招「望穿秋水」躲过了$N的攻势。\n",
        "$n一招「飞鸟投林」纵身跃起，倏忽已落至$N身后。\n",
        "$n左一摇，右一晃，一招「云海茫茫」已轻松闪过。\n",
	"$n一招「天玑离枢」轻轻巧巧地避了开去。\n",
	"只见$n身影一晃，一式「天璇乱步」早已避在七尺之外。\n",
	"$n使出「倒转天权」，轻轻松松地闪过。\n",
	"$n左足一点，一招「逐影天枢」腾空而起，避了开去。\n",
	"可是$n使一招「风动玉衡」，身子轻轻飘了开去。\n",
	"$n身影微动，已经藉一招「开云薄雾」轻轻闪过。\n",
	"但是$n一招「瑶光音迟」使出，早已绕到$N身後！\n",
        "$n身形往上拔起，一招「把酒飞仙」，一个转折落在数尺之外。\n",
        "$n身随意转，一式「仙人敬酒」，往旁窜开数尺，躲了开去。\n",
        "但是$n身形飘忽，轻轻一纵，一招「醉仙望月」，轻而易举的避开这一击。\n",


        });
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");}
int valid_learn(object me) {return 1;}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{       
               if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力太差了，不能练纤云身法。\n");
        me->receive_damage("kee", 30);
        return 1;
}
string perform_action_file(string action)
{
        return   __DIR__"xianyun/" + action;
}

int effective_level() {
        return 16;

}
int query_faith_req(int skill) {
	return 10+skill*3;
}

/*
mapping enable_req() {
        return( ([
                "force":"yunu-xinfa",
        ]) );
}
*/
                  
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "yunu-xinfa" ){
        return( ([ 
                "force":"yunu-xinfa",     
        ]) );
        }else if( this_player()->query_skill_mapped("force") == "jiuyin-shengong" ){
        return( ([ 
                "force":"jiuyin-shengong",   
        ]) );
        }else{
        return( ([ 
                "force":"xiantian-gong",   
        ]) );
        }

}


