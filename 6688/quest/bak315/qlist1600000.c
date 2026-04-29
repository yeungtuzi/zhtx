inherit SKILL;

mapping *quest = ({
	([	"quest":	"黎生",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"曲灵风",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"侍卫",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"马俱为",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"余洪兴",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"蓝止萍",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

	([	"quest":	"[1;35m紫霜血蝉衣[2;37;0m",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;35m魔鞭翩珑[2;37;0m",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;33m软金束带[2;37;0m",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[32m穿花蛇影鞋[2;37;0m",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"彭有敬",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"卜鹰",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"弯刀",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"韦一笑",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"玄苦大师",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"玄难大师",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"简长老",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[33m秦歌[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[33m多情刀[2;37;0m",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"梁长老",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"鲁有脚",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"玄悲大师",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"成不优",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"白色长衫",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"瑷伦",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

	([	"quest":	"[1;36m宝蓝缎衫[2;37;0m",
		"quest_type":	"寻",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"丁春秋",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

	([	"quest":	"唐云",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

	([	"quest":	"孙不二",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"贾人达",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),
	([	"quest":	"[35m林太平[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"[1;35m段飞熊[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;37m苏芮[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
