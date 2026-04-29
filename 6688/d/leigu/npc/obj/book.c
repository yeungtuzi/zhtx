// book.c

inherit ITEM;

void create()
{
        string *names = ({ 
		"<<三字经>> ","<<百家姓>>","<<幼学琼林>>","<<论语>>",
		"<<诗经>>" , "<<九韬>>", "<<太公辩>>", "<<梁父文集>>", 
		"<<说律>>", "<<古文志>>", "<<乡书>>", "<<佾风斋诗集>>",
                "<<寒士列传>>", 
        });

        set_name( names[random(sizeof(names))], ({ "book" }));
        set_weight(600+random(600));
        set("unit", "本");
        set("long", "这是一本读书人常看的书。\n");
        set("value", 1000+random(100)*10);
        set("skill", ([
                "name":                 "literate",
                "exp_required": random(100), 
                "sen_cost":             10,
                "difficulty":   5,
                "max_skill":    40+random(12) 
        ]) );
}
