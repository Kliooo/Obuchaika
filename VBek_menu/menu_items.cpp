#include "menu_items.hpp"
#include "menu_functions.hpp"

namespace {
	const VBek::MenuItem* const main_children[] = {
		&VBek::EXIT,
		&VBek::STUDY
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const VBek::MenuItem VBek::MAIN = {
	nullptr, VBek::show_menu, nullptr, main_children, main_size
};

namespace {
	const VBek::MenuItem* const study_children[] = {
		&VBek::STUDY_GO_BACK,
		&VBek::ALGEBRA,
		&VBek::MATHAN
	};
	const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const VBek::MenuItem VBek::STUDY = {
	"1 - Хочу учиться математике", VBek::show_menu, &VBek::MAIN, study_children, study_size
};
const VBek::MenuItem VBek::EXIT = {
	"0 - Я лучше пойду полежу...", VBek::exit, &VBek::MAIN
};

namespace {
	const VBek::MenuItem* const algebra_children[] = {
		&VBek::ALGEBRA_GO_BACK,
		&VBek::ALGEBRA_SUMM,
		&VBek::ALGEBRA_SUBSTRACT,
		&VBek::ALGEBRA_MULTIPLY,
		&VBek::ALGEBRA_DIVIDE
	};
	const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
}

const VBek::MenuItem VBek::ALGEBRA = {
	"1 - Хочу изучать алгебру", VBek::show_menu, &VBek::STUDY, algebra_children, algebra_size
};

const VBek::MenuItem VBek::ALGEBRA_SUMM = {
	"1 - Хочу учиться складывать", VBek::algebra_summ, &VBek::ALGEBRA
};
const VBek::MenuItem VBek::ALGEBRA_SUBSTRACT = {
	"2 - Хочу учиться вычитать", VBek::algebra_substrect, &VBek::ALGEBRA
};
const VBek::MenuItem VBek::ALGEBRA_MULTIPLY = {
	"3 - Хочу учиться умножать", VBek::algebra_multiply, &VBek::ALGEBRA
};
const VBek::MenuItem VBek::ALGEBRA_DIVIDE = {
	"4 - Хочу учиться делить", VBek::algebra_divide, &VBek::ALGEBRA
};
const VBek::MenuItem VBek::ALGEBRA_GO_BACK = {
	"0 - Хочу в главное меню", VBek::go_back, &VBek::ALGEBRA
};

namespace {
	const VBek::MenuItem* const mathan_children[] = {
		&VBek::MATHAN_GO_BACK,
		&VBek::MATHAN_DIFFERENTIATION,
		&VBek::MATHAN_INTEGRATION
	};
	const int mathan_size = sizeof(mathan_children) / sizeof(mathan_children[0]);
}

const VBek::MenuItem VBek::MATHAN = {
	"2 - Хочу изучать математический анализ", VBek::show_menu, &VBek::STUDY, mathan_children, mathan_size
};
const VBek::MenuItem VBek::STUDY_GO_BACK = {
	"0 - Хочу в главное меню", VBek::go_back, &VBek::STUDY
};

const VBek::MenuItem VBek::MATHAN_DIFFERENTIATION = {
	"1 - Хочу изучить дифференциальное исчисление", VBek::mathan_differentiation, &VBek::MATHAN
};
const VBek::MenuItem VBek::MATHAN_INTEGRATION = {
	"2 - Хочу изучить интегральное исчисление", VBek::mathan_integration, &VBek::MATHAN
};
const VBek::MenuItem VBek::MATHAN_GO_BACK = {
	"0 - Хочу в главное меню", VBek::go_back, &VBek::MATHAN
};
