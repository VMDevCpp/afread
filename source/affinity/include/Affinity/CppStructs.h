// Copyright (c) 2020 Vladimir Mamonov
// Licensed under the MIT license.

#ifndef AFFINITY_CPPSTRUCTS_H
#define AFFINITY_CPPSTRUCTS_H

/* This file is auto generated                               */
/* Do not edit it manually                                   */

#include "Affinity/Model.h"
#include "Affinity/Utils.h"

#include <array>
#include <string>
#include <vector>

namespace AffinityReader::CppModel {

template <class T>
using vector = std::vector<T>;
using string = std::string;
template <class T, std::size_t N>
using array = std::array<T, N>;

struct BaseAdjustment;
struct BaseEffect;
struct BaseBitm;
struct BaseFill;
struct BaseShape;
struct BaseFrms;
struct BGrd;
struct BlnR;
struct BrDy;
struct CnMP;
struct CoDe;
struct CrpP;
struct CrvD;
struct DFFO;
struct DcHI;
struct DocS;
struct DyBm;
struct ExBF;
struct FDsc;
struct FTXR;
struct FilS;
struct Font;
struct ForC;
struct Futr;
struct GAtt;
struct GStr;
struct GlAS;
struct GrMP;
struct Grad;
struct Grup;
struct IBRB;
struct ICC;
struct ICCP;
struct ILDO;
struct ILGI;
struct ILSN;
struct ILTI;
struct LDsc;
struct LR3D;
struct LStr;
struct LSty;
struct Layt;
struct LigS;
struct Macr;
struct Matx;
struct ObjS;
struct OpAV;
struct PAtt;
struct PCrv;
struct PCvD;
struct PLig;
struct PSRe;
struct PTCf;
struct PTEq;
struct PTNd;
struct PaAS;
struct Per_42;
struct PfPr;
struct Prst;
struct PthT;
struct Quad;
struct RBMI;
struct RGBA;
struct Rec;
struct Rstr;
struct SNAR;
struct SPst;
struct SRst;
struct SSAS;
struct Scal;
struct Sctn;
struct Sele;
struct ShpN;
struct Slic;
struct SnpG;
struct SpRV;
struct SpRe;
struct Spln;
struct Sprd;
struct Stop;
struct Stry;
struct TBFR;
struct TBSO;
struct TStS;
struct TSty;
struct TbFt;
struct TexS;
struct TxFU;
struct TxFl;
struct TxtA;
struct UnSR;
struct UndR;
struct Undo;
struct VwPD;
struct v_CB1;
struct v_CB2;
struct v_CB3;
struct v_CB4;
struct v_CB5;
struct v_C1;
struct v_C2;

#pragma pack(push, 1)

struct BaseExport
{
	enum class Type
	{
		Unknown,
		EOEp,
		EOGf,
		EOHD,
		EOJp,
		EOPS,
		EOPd,
		EOPn,
		EOSv,
		EOTf,
		EOTg,
		EOXR,
		FExO,
	};
	Type base_type = Type::Unknown;

	struct ICCP* ICCP;
	bool         EmIP;
	bool         EmMt;
	RGBA*        Matt;
	EnumT        Rsmp;
	bool         Bled;
	bool         TxCr;
	bool         isds;
	double       dadi;
	bool         jpeg;
	bool         iurd;
	double       rdpi;
	EnumT        RaPo;
	bool         isct;
	bool         ahcl;
	EnumT        PxFm;
	EnumT        PlTy;
	uint16_t     PlSz;
	void*        UPlt;
	EnumT        Comp;
	bool         Plts;
};

struct BaseLayer
{
	enum class Type
	{
		Unknown,
		BCRA,
		BWRA,
		CBRA,
		Comp,
		CrRA,
		EmbN,
		FRst,
		FlRN,
		Grup,
		HsRA,
		ImgN,
		LeRA,
		MPIN,
		PCrv,
		PfRA,
		Rstr,
		SCRA,
		SHRA,
		Scop,
		ShpN,
		StkN,
		TxtA,
		TxtF,
		TxtT,
		VbRA,
		WBRA,
		Sprd,
		v_3DLA, /* NOLINT(readability-identifier-naming) */
		CMRA,
		GrRA,
		InRA,
		MRst,
		OCRN,
		PoRA,
		SPRA,
		SpTA,
		ThRA,
		CnsN,
		CPTx,
		ExRA,
		RcRA,
		SNEN,
		TxtS,
		SlcP,
		Slic,
		SNRR,
		ShRN,
		ScPr,
		ObjS,
	};
	Type base_type = Type::Unknown;

	/* v_3DLP*, BCP_38*, BWP_38*, CIPP*, CnMP*, CoBP*, CrvP*, ExpP*, GrMP*, HSSP*, LeFP*, LevP*, PosP*, RecP*, SCoP*, SHiP*, STPa*, SoPP*,
	 * ThrP*, VibP*, WhBP* */
	BaseAdjustment* AdjP;
	int32_t         TrCn;
	EnumT           TrAn;
	int32_t         TraC;
	double          TrFP[2];
	bool            TrFV;
	double          Xfrm[6];
	double          SrBx[4];
	double          SrPB[4];
	double          FTxS[6];
	EnumT           Blnd;
	bool            PasT;
	BlnR*           BlRa;
	string          Desc;
	RGBA*           TagC;
	string          DefD;
	bool            Visi;
	float           Opac;
	float           FOpc;
	/* BevE*, ColO*, Gaus*, GrdO*, InnG*, InnS*, OutG*, PhgB*, Shad*, Strk* */
	vector<BaseEffect*> FiEf;
	bool                Edtb;
	bool                MEtb;
	void*               Data;
	bool                CEdb;
	vector<string>      Frst;
	vector<string>      Scnd;
	EnumT               Hyty;
	string              Hypr;
	EnumT               HyTr;
	EnumT               CLiT;
	EnumT               TWSt;
	double              TWBo[4];
	/* DyBm*, EmbR* */
	BaseBitm* Bitm;
	int32_t   BitR[4];
	int32_t   BitI[4];
	int32_t   CMsk;
	EnumT     ProT;
	void*     Unpr;
	Matx*     WRot;
	double    Lati;
	double    Long;
	double    Roll;
	double    FOV;
	Per_42*   Psp_42;
	bool      ExtE;
	Quad*     Pspv;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, FlRN*, GrRA*, Grup*, HsRA*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*, RcRA*,
	 * Rstr*, SCRA*, SHRA*, SPRA*, ShpN*, SpTA*, ThRA*, VbRA*, WBRA* */
	vector<BaseLayer*> AdCh;
	EnumT              ComO;
	ILTI*              TLnk;
	/* Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer* BlMM;
	/* Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer* VisM;
	/* Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer* FiEM;
	ILSN*      SLnk;
	ILGI*      GLnk;
	/* BCRA*, BWRA*, CBRA*, CMRA*, CPTx*, CnsN*, Comp*, CrRA*, EmbN*, ExRA*, FRst*, FlRN*, Grup*, HsRA*, ImgN*, LeRA*, MPIN*, MRst*, PCrv*,
	 * PfRA*, RcRA*, Rstr*, SCRA*, SHRA*, SNEN*, SNRR*, Scop*, ShRN*, ShpN*, StkN*, TxtA*, TxtF*, TxtS*, TxtT*, VbRA*, WBRA* */
	vector<BaseLayer*> Chld;
	/* CnsN*, Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	BaseLayer* TWMa;
	/* FDsc*, FilS* */
	BaseFill* BFil;
	LDsc*     LSty;
	/* Comp*, Grup*, PCrv*, Scop*, ShpN*, TxtF* */
	BaseLayer* VBFM;
	/* Comp*, Grup*, PCrv*, Scop*, ShpN*, TxtF* */
	BaseLayer* VTrM;
	/* Comp*, Grup*, PCrv*, Scop*, ShpN*, TxtF* */
	BaseLayer*    VLSM;
	uint32_t      BFCr;
	vector<FDsc*> BFFl;
	/* FDsc*, FilS* */
	BaseFill*     Trns;
	uint32_t      LICr;
	vector<LDsc*> LILn;
	vector<FDsc*> LIFl;
	bool          IsVF;
	uint32_t      Ctrl;
	EnumT         Anch;
	double        OCRc[4];
	vector<EnumT> DrwO;
	EnumT         Spac;
	EnumT         IPlc;
	PthT*         Path;
	uint64_t      Flsz;
	int64_t       MfTm;
	EnumT         FTyp;
	PthT*         RPth;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* DsMa;
	double     SrTr[6];
	double     SrPT[6];
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* EdMa;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* TMas;
	string     GooI;
	/* Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtF* */
	BaseLayer* HKMs;
	/* FDsc*, FilS* */
	BaseFill* PFil;
	bool      HsFC;
	/* PCrv*, ShpN* */
	BaseLayer* PFMs;
	ILDO*      DLnk;
	PCvD*      Crvs;
	double     CvsB[4];
	EnumT      CvWi;
	/* PCrv*, ShpN*, TxtF* */
	BaseLayer*               BGMs;
	BGrd*                    Opts;
	vector<array<double, 4>> MrgA;
	vector<bool>             UMgA;
	string                   MiID;
	vector<curve16_t>        CGds;
	vector<bool>             UCGA;
	/* MRst*, Rstr* */
	BaseLayer* MRaM;
	/* ShCR*, ShCg*, ShCl*, ShCr*, ShDA*, ShDS*, ShHt*, ShNR*, ShPi*, ShPy*, ShRR*, ShSS*, ShSg*, ShSt*, ShTr*, ShTz*, ShpD*, ShpE*, ShpT*
	 */
	BaseShape*     Shpe;
	double         ShpB[4];
	struct XCfg*   XCfg;
	bool           ExIn;
	string         ExFn;
	bool           ABEn;
	vector<double> GdsV;
	bool           GdsA;
	bool           USnG;
	SnpG*          SGrd;
	vector<double> GdsH;
	/* TxtA*, TxtF* */
	BaseLayer* StMa;
	Stry*      StSt;
	/* TxtA*, TxtF* */
	BaseLayer* TxFM;
	/* ArFr*, CoFr*, PaFr*, TbFr* */
	BaseFrms* TxtH;
	Layt*     TxtL;
	bool      IgTW;
	bool      IgBG;
	TxFl*     Flow;
};

struct BaseBrush
{
	enum class Type
	{
		Unknown,
		BmRB,
		IBRB,
		RRBr,
		SRBr,
	};
	Type base_type = Type::Unknown;

	vector<DyBm*>  TipT;
	string         BUid;
	float          Opac;
	float          Spac;
	EnumT          BlMo;
	bool           SABM;
	bool           WetE;
	Spln*          WeES;
	bool           SAWE;
	BrDy*          Flow;
	BrDy*          Accn;
	BrDy*          Size;
	BrDy*          Hard;
	BrDy*          Shap;
	BrDy*          Angl;
	BrDy*          ScaX;
	BrDy*          ScaY;
	BrDy*          HueS;
	BrDy*          SatS;
	BrDy*          LumS;
	BrDy*          TipC;
	DyBm*          MskT;
	EnumT          MkTM;
	double         MkTS;
	bool           Strk;
	double         Head;
	double         Tail;
	bool           RptB;
	EnumT          CnrS;
	bool           SATI;
	int32_t        ToID;
	vector<IBRB*>  SubB;
	EnumT          SMod;
	EnumT          SSMd;
	bool           SSSz;
	bool           SSSp;
	vector<string> Frst;
	vector<string> Scnd;
};

struct BaseColor
{
	enum class Type
	{
		Unknown,
		CMYK,
		GRAY,
		HSLA,
		LABA,
		Pant,
		RGBA,
		RegC,
	};
	Type base_type = Type::Unknown;

	double v_nse;
	string v_glb;
	double v_tnt;
};

struct BaseFill
{
	enum class Type
	{
		Unknown,
		FDsc,
		HlkA,
		LDsc,
		OpAA,
		OtAt,
		FilG,
		FilN,
		FilS,
	};
	Type base_type = Type::Unknown;
};

struct BaseGlys
{
	enum class Type
	{
		Unknown,
		BrGl,
		FlrG,
		LLGl,
		PgNG,
	};
	Type base_type = Type::Unknown;
};

struct BaseAtt
{
	enum class Type
	{
		Unknown,
		AFAt,
		Deco,
		DrCp,
		LisA,
		TabS,
		TocA,
	};
	Type base_type = Type::Unknown;

	bool   Enbl;
	string SNam;
	CoDe*  SDlt;
};

struct BaseDels
{
	enum class Type
	{
		Unknown,
		AuFD,
		DrpD,
		FSDe,
		GADD,
		GAID,
		GAOD,
		GASD,
		OTFD,
		PADD,
		PAID,
		PAOD,
		SLAD,
		PADS,
	};
	Type base_type = Type::Unknown;

	/* AFAt*, DrCp* */
	BaseAtt* Att;
	int32_t  Fild;
	int32_t  Key_; /* NOLINT(readability-identifier-naming) */
};

struct BaseShape
{
	enum class Type
	{
		Unknown,
		ShCR,
		ShCg,
		ShCl,
		ShCr,
		ShDA,
		ShDS,
		ShHt,
		ShNR,
		ShPi,
		ShPy,
		ShSS,
		ShSg,
		ShSt,
		ShTr,
		ShTz,
		ShpD,
		ShpE,
		ShpT,
		ShCE,
		ShRR,
	};
	Type base_type = Type::Unknown;

	bool     AbSz;
	bool     Lock;
	float    ShCR[4];
	float    TlHg;
	float    TlEP;
	float    IRad;
	float    Curv;
	uint16_t Pnts;
	float    IRae;
	uint16_t Side;
	float    Pos;
};

struct BaseEffect
{
	enum class Type
	{
		Unknown,
		BevE,
		ColO,
		Gaus,
		GrdO,
		InnG,
		InnS,
		OutG,
		PhgB,
		Shad,
		Strk,
	};
	Type base_type = Type::Unknown;

	bool   Enab;
	EnumT  BlnM;
	double Opac;
	bool   SclO;
	double Dept;
	double Radi;
	bool   Disr;
	double Sftn;
	Spln*  Prof;
	/* CMYK*, HSLA*, LABA*, RGBA* */
	BaseColor* Colr;
	FDsc*      GrFl;
	double     Comp;
	double     Offs;
	double     Angl;
};

struct BaseSubSel
{
	enum class Type
	{
		Unknown,
		CvHS,
		TexS,
	};
	Type base_type = Type::Unknown;
};

struct BaseProp
{
	enum class Type
	{
		Unknown,
		ACrt,
		AbMp,
		Adjs,
		AstP,
		Brus,
		CrPP,
		DPOp,
		Filp,
		MacP,
		OSty,
		PTCP,
		PfPr,
		SGrP,
		SPPp,
		TExM,
		TonP,
	};
	Type base_type = Type::Unknown;
};

struct BaseExCsts
{
	enum class Type
	{
		Unknown,
		ExCI,
		ExCt,
	};
	Type base_type = Type::Unknown;

	EnumT  type;
	string cnst;
	string desc;
};

struct BaseExVals
{
	enum class Type
	{
		Unknown,
		ExV2,
		ExVI,
		ExVR,
	};
	Type base_type = Type::Unknown;
};

struct BaseFrms
{
	enum class Type
	{
		Unknown,
		ArFr,
		CoFr,
		PaFr,
		TbFr,
	};
	Type base_type = Type::Unknown;

	double FrmB[4];
};

struct BaseCmd
{
	enum class Type
	{
		Unknown,
		AAAC,
		AAMC,
		AARC,
		ACCm,
		AESC,
		AOSC,
		ARCm,
		CRGl,
		ChMA,
		CmCm,
		CrSl,
		DCCm,
		DNCm,
		DPro,
		EnBE,
		EnCO,
		EnGA,
		EnGO,
		EnIS,
		EnIg,
		EnOg,
		EnPB,
		EnSh,
		EnSt,
		ExIn,
		FAFH,
		FFCm,
		FmTC,
		GrMA,
		GrNC,
		InGl,
		MC2C,
		MvNC,
		SBMC,
		SDeC,
		SLsC,
		SSNS,
		SSaC,
		SViC,
		SetE,
		TrCm,
		TrSl,
		UANC,
		XMgC,
		XStC,
		ARFC,
		PNoC,
		PRNS,
		RRFC,
		SCER,
		SF2C,
		SSFH,
		SSLF,
		CMTC,
		ClrX,
		ForC,
		MgDC,
		CASC,
	};
	Type base_type = Type::Unknown;

	bool Assi;
	/* CASC*, CmCm* */
	BaseCmd* Innr;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, HsRA*, InRA*, LeRA*, MRst*, OCRN*, PfRA*, PoRA*, RcRA*, SCRA*, SHRA*,
	 * SPRA*, SpTA*, ThRA*, VbRA*, WBRA* */
	BaseLayer* Node;
	LStr*      LDsc;
	bool       Opaq;
	bool       UsRS;
	EnumT      Dire;
	bool       Prev;
	bool       ArtC;
	bool       AAtC;
	bool       CArC;
	bool       Work;
	bool       Done;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*, RcRA*,
	 * Rstr*, SCRA*, SHRA*, SPRA*, Scop*, ShpN*, SpTA*, ThRA*, TxtA*, VbRA*, WBRA* */
	vector<BaseLayer*> NodA;
	bool               AdSC;
	bool               AppD;
	bool               TTTa;
	bool               UBLS;
	void*              Pres;
	bool               AndS;
	struct Sele*       NewS;
	int32_t            FrcC;
	bool               UsFl;
	bool               ANme;
	double             InRc[4];
	bool               AARp;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN*, Sprd*, TxtA*, WBRA* */
	BaseLayer*    InsT;
	EnumT         InsM;
	EnumT         CLis;
	EnumT         OInM;
	EnumT         NInM;
	bool          MdTc;
	struct Sele*  OSCo;
	vector<void*> Fir3;
	vector<void*> Sec3;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir4;
	vector<PSRe*>      Sec4;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir6;
	vector<PSRe*>      Sec6;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir7;
	vector<PSRe*>      Sec7;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fir1;
	vector<PSRe*>      Sec1;
	/* Grup*, Scop* */
	vector<BaseLayer*> Fr10;
	vector<PSRe*>      Sc10;
	/* Grup*, Scop* */
	vector<BaseLayer*> Fr12;
	vector<PSRe*>      Sc12;
	/* Grup*, Scop* */
	vector<BaseLayer*> Fr11;
	vector<PSRe*>      Sc11;
	vector<void*>      Fir8;
	vector<void*>      Sec8;
	vector<void*>      Fir9;
	vector<void*>      Sec9;
	vector<void*>      Fir5;
	vector<void*>      Sec5;
	/* Grup*, Scop*, ShpN*, Sprd* */
	vector<BaseLayer*> Fr14;
	vector<PSRe*>      Sc14;
	vector<void*>      Fr16;
	vector<void*>      Sc16;
	vector<void*>      Fr25;
	vector<void*>      Sc25;
	vector<void*>      Fr17;
	vector<void*>      Sc17;
	vector<void*>      Fr18;
	vector<void*>      Sc18;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr19;
	vector<PSRe*>      Sc19;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr13;
	vector<PSRe*>      Sc13;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr21;
	vector<PSRe*>      Sc21;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr22;
	vector<PSRe*>      Sc22;
	vector<void*>      Fr23;
	vector<void*>      Sc23;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr24;
	vector<PSRe*>      Sc24;
	vector<Sprd*>      Fr26;
	vector<PSRe*>      Sc26;
	/* Grup*, Scop*, Sprd* */
	vector<BaseLayer*> Fr15;
	vector<PSRe*>      Sc15;
	vector<void*>      lnkd;
	/* CMRA*, GrRA*, Grup*, ImgN*, Rstr*, Scop*, ShpN*, TxtA* */
	vector<BaseLayer*> ulkd;
	struct Sele*       Sele;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer* Layr;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, Grup*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*,
	 * RcRA*, Rstr*, SCRA*, SHRA*, SPRA*, ScPr*, Scop*, ShpN*, SpTA*, ThRA*, TxtA*, VbRA*, WBRA* */
	vector<BaseLayer*> mapo;
	bool               UsTS;
	/* Grup*, ObjS*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> OldN;
	vector<GlAS*>      OlGA;
	vector<PaAS*>      OlPA;
	vector<void*>      Fir2;
	vector<void*>      Sec2;
	void*              SrUC;
	GStr*              Glyp;
	vector<void*>      NwTV;
	vector<void*>      OdTV;
	vector<PAtt*>      OPBV;
	vector<PAtt*>      OPAV;
	vector<GAtt*>      OGAV;
	EnumT              SeNT;
	UnSR*              OlTR;
	UnSR*              NwTR;
	void*              CGlA;
	GAtt*              OTGA;
	bool               TocC;
	bool               NoIn;
	SpRV*              IRec;
	/* CnMP*, GrMP* */
	BaseAdjustment* Para;
	bool            Stac;
	/* ACCm*, ARFC*, ExIn*, PNoC*, PRNS*, RRFC*, SCER*, SF2C*, SSFH*, SSLF*, SSNS* */
	vector<BaseCmd*> Objs;
	bool             Prog;
	bool             GnHT;
	int32_t          DIdx;
	/* Grup*, PCrv*, Rstr*, ShpN* */
	vector<BaseLayer*>       OlPS;
	vector<void*>            NewB;
	vector<array<double, 6>> OldT;
	bool                     Enab;
	vector<bool>             OldE;
	bool                     EnID;
	vector<bool>             OlE2;
	vector<GlAS*>            OldG;
	vector<void*>            Fak1;
	vector<void*>            Fak2;
	bool                     VsCh;
	bool                     VsRs;
	double                   Tole;
	vector<DyBm*>            RedT;
	PAtt*                    RPA0;
	PAtt*                    RPA1;
	GAtt*                    RGA0;
	GAtt*                    RGA1;
	double                   InvR[4];
	bool                     RasS;
	bool                     CMSl;
	int32_t                  DefM;
	bool                     uTSl;
	bool                     eTSl;
	bool                     Vali;
	vector<struct UndR*>     UndR;
	bool                     Defs;
	void*                    NDef;
	void*                    ODef;
	bool                     AThm;
	bool                     IINS;
	/* EOEp*, EOGf*, EOHD*, EOJp*, EOPS*, EOPd*, EOPn*, EOSv*, EOTf*, EOTg*, EOXR* */
	BaseExport* ExOp;
	bool        DidD;
	/* FilG*, FilS* */
	BaseFill*            Fill;
	uint32_t             FilI;
	bool                 CopT;
	bool                 ClrS;
	bool                 CSDf;
	bool                 Crct;
	int32_t              FMsk;
	FDsc*                SFDe;
	vector<struct LDsc*> OldL;
	vector<struct LDsc*> NewL;
	vector<void*>        NwBm;
};

struct BaseScObjs
{
	enum class Type
	{
		Unknown,
		ScAN,
		ScIN,
		ScRN,
	};
	Type base_type = Type::Unknown;

	/* Grup*, Scop*, ShpN*, Sprd*, WBRA* */
	BaseLayer* pnde;
	EnumT      nclt;
	bool       frnt;
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CrRA*, ExRA*, GrRA*, Grup*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*, PoRA*,
	 * RcRA*, Rstr*, SCRA*, SHRA*, SPRA*, Scop*, ShpN*, SpTA*, ThRA*, TxtA*, VbRA*, WBRA* */
	BaseLayer* node;
	EnumT      Dire;
	bool       Prev;
	bool       ArtC;
	bool       AAtC;
	bool       CArC;
};

struct BaseFilt
{
	enum class Type
	{
		Unknown,
		Clar,
		Clrt,
		RDF2,
		RGBC,
		RHPC,
		RLdC,
		RLig,
		RUSC,
		RVgC,
	};
	Type base_type = Type::Unknown;

	double        Radi;
	vector<void*> OlCm;
	void*         NwCm;
	bool          Live;
	bool          AbrP;
	SpRV*         IRec;
	vector<void*> RedT;
	float         PMin;
	float         PMax;
	vector<void*> Fir3;
	vector<void*> Sec3;
	vector<void*> Fir4;
	vector<void*> Sec4;
	vector<void*> Fir6;
	vector<void*> Sec6;
	vector<void*> Fir7;
	vector<void*> Sec7;
	vector<void*> Fir1;
	vector<void*> Sec1;
	vector<void*> Fr10;
	vector<void*> Sc10;
	vector<void*> Fr12;
	vector<void*> Sc12;
	vector<void*> Fr11;
	vector<void*> Sc11;
	vector<void*> Fir8;
	vector<void*> Sec8;
	vector<void*> Fir2;
	vector<void*> Sec2;
	vector<void*> Fir9;
	vector<void*> Sec9;
	vector<void*> Fir5;
	vector<void*> Sec5;
	vector<void*> Fr13;
	vector<void*> Sc13;
	vector<void*> Fr14;
	vector<void*> Sc14;
	vector<void*> Fr15;
	vector<void*> Sc15;
	vector<void*> Fr16;
	vector<void*> Sc16;
	vector<void*> Fr17;
	vector<void*> Sc17;
	vector<void*> Fr18;
	vector<void*> Sc18;
	vector<void*> Fr21;
	vector<void*> Sc21;
	vector<void*> Fr22;
	vector<void*> Sc22;
	vector<void*> Fr23;
	vector<void*> Sc23;
	vector<void*> Fr24;
	vector<void*> Sc24;
	void*         Sele;
	void*         Layr;
	EnumT         Dire;
	bool          Prev;
	bool          ArtC;
	bool          AAtC;
	bool          CArC;
	vector<void*> Fr25;
	vector<void*> Sc25;
	vector<void*> Fr19;
	vector<void*> Sc19;
	vector<void*> Fr26;
	vector<void*> Sc26;
};

struct BaseAdjustment
{
	enum class Type
	{
		Unknown,
		v_3DLP, /* NOLINT(readability-identifier-naming) */
		BCP_38, /* NOLINT(readability-identifier-naming) */
		BWP_38, /* NOLINT(readability-identifier-naming) */
		CIPP,
		CnMP,
		CoBP,
		CrvP,
		ExpP,
		GrMP,
		HSSP,
		LeFP,
		LevP,
		PosP,
		RecP,
		SCoP,
		SHiP,
		STPa,
		SoPP,
		ThrP,
		VibP,
		WhBP,
	};
	Type base_type = Type::Unknown;

	vector<float> Weig;
	float         Gamm;
	uint16_t      Vers;
};

struct BaseBitm
{
	enum class Type
	{
		Unknown,
		DyBm,
		EmbR,
	};
	Type base_type = Type::Unknown;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_3DLA: public BaseLayer
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_3DLP: public BaseAdjustment
{
	LR3D* Cube;
};

struct AAAC: public BaseCmd
{
};

struct AAMC: public BaseCmd
{
};

struct AARC: public BaseCmd
{
};

struct ACCm: public BaseCmd
{
	struct Sele* OldS;
};

struct ACrt: public BaseProp
{
	string AcKy;
	string AcRs;
};

struct AESC: public BaseCmd
{
	vector<Sprd*> Spds;
};

struct AFAt: public BaseAtt
{
	int32_t MxWC;
	GStr*   Left;
};

struct AOSC: public BaseCmd
{
	ObjS*         Styl;
	vector<void*> OlTS;
	vector<void*> OTbl;
	bool          isDD;
};

struct ARCm: public BaseCmd
{
	/* BWRA*, Rstr* */
	BaseLayer*               TNod;
	bool                     Empt;
	bool                     Mask;
	vector<array<double, 4>> InvB;
	struct Sele*             OldS;
};

struct ARFC: public BaseCmd
{
	FilS* Popp;
};

struct AbMp: public BaseProp
{
	string AbVl;
};

struct Adjs: public BaseProp
{
	/* v_3DLA*, BCRA*, BWRA*, ExRA*, GrRA*, HsRA*, LeRA*, PoRA*, RcRA*, SHRA*, SPRA*, ThRA*, VbRA*, WBRA* */
	BaseLayer* Adjs;
};

struct ApVs
{
	int32_t Majr;
	int32_t Minr;
	int32_t Bild;
	int32_t Revn;
	string  Prod;
	string  Plat;
	string  Date;
};

struct ArFr: public BaseFrms
{
	EnumT  ArtA;
	double ArtV;
};

struct AstP: public BaseProp
{
	/* CnsN*, Comp*, Grup*, PCrv*, ShpN* */
	BaseLayer* AstP;
	EnumT      AstF;
	double     DPI;
};

struct AuFD: public BaseDels
{
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct BCP_38: public BaseAdjustment
{
	float Brig;
	float Ctrs;
	bool  Linr;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct BWP_38: public BaseAdjustment
{
	float RedC;
	float Gree;
	float Blue;
	float Cyan;
	float Mage;
	float Yell;
};

struct BCRA: public BaseLayer
{
};

struct BGrd
{
	bool    UGrd;
	double  Strt;
	double  Spac;
	EnumT   Rlto;
	Color32 Colr;
};

struct BWRA: public BaseLayer
{
};

struct BevE: public BaseEffect
{
	EnumT  Beve;
	double Azim;
	double Elev;
	bool   Invt;
	EnumT  ShBM;
	double ShOp;
	/* HSLA*, RGBA* */
	BaseColor* ShCl;
	/* HSLA*, RGBA* */
	BaseColor* HiCl;
};

struct Blck
{
	int32_t      Rect[4];
	int32_t      IRct[4];
	EmbeddedData Data;
};

struct BlnR
{
	double BGam;
	CrvD*  AGam;
	Spln*  SMSp;
};

struct BmRB: public BaseBrush
{
};

struct BrDy
{
	float        DynV;
	float        DyVa;
	EnumT        DynC;
	EnumT        DyVM;
	struct Spln* Spln;
	EnumT        DynR;
};

struct BrGl: public BaseGlys
{
	EnumT HdBk;
};

struct Brus: public BaseProp
{
	/* IBRB*, RRBr*, SRBr* */
	BaseBrush* Brus;
};

struct CASC: public BaseCmd
{
};

struct CBRA: public BaseLayer
{
};

struct CFPa
{
	vector<double> ColW;
	vector<double> GutW;
	EnumT          Algn;
	double         Padd[4];
};

struct CIPP: public BaseAdjustment
{
	string SouP;
	string DesP;
};

struct CMRA: public BaseLayer
{
};

struct CMTC: public BaseCmd
{
	double                   Rect[4];
	EnumT                    TrnT;
	double                   Tran[6];
	vector<array<double, 4>> Area;
	bool                     NeeM;
};

struct CMYK: public BaseColor
{
	ColorCMYK v_col;
};

struct CPTx: public BaseLayer
{
};

struct CRGl: public BaseCmd
{
	void*        Dlta;
	uint64_t     SLoc;
	uint64_t     SLen;
	uint64_t     RLoc;
	uint64_t     RLen;
	bool         MkTx;
	bool         PrCr;
	struct Sele* OldS;
};

struct ChGl
{
	uint32_t Char;
};

struct ChMA: public BaseCmd
{
	vector<CnMP*> OldP;
};

struct Clar: public BaseFilt
{
};

struct ClrX: public BaseCmd
{
	string OMet;
};

struct Clrt: public BaseFilt
{
	double Strn;
};

struct CmCm: public BaseCmd
{
};

struct CnMP: public BaseAdjustment
{
};

struct CnsN: public BaseLayer
{
};

struct CoBP: public BaseAdjustment
{
	float ShCR;
	float ShMG;
	float ShYB;
	float MiCR;
	float MiMG;
	float MiYB;
	float HiCR;
	float HiMG;
	float HiYB;
	bool  PeLu;
};

struct CoDe
{
	/* AuFD*, DrpD*, FSDe*, GADD*, GAID*, GAOD*, GASD*, OTFD*, PADD*, PAID*, PAOD*, SLAD* */
	vector<BaseDels*> Dels;
	LStr*             LDsc;
};

struct CoFr: public BaseFrms
{
	vector<double> ColW;
	EnumT          Algn;
	vector<double> GutW;
	double         Padd[4];
};

struct ColO: public BaseEffect
{
};

struct Comp: public BaseLayer
{
};

struct CrPP: public BaseProp
{
	CrpP* Prst;
};

struct CrRA: public BaseLayer
{
};

struct CrSl: public BaseCmd
{
	Sprd*        Sprd;
	void*        SlPg;
	Slic*        Slic;
	struct Sele* NSel;
	struct Sele* Osel;
	int32_t      Rect[4];
	bool         SNSl;
};

struct CrpP
{
	double  Wdth;
	double  Hght;
	bool    Abs;
	uint8_t Unit;
	double  DPI;
};

struct CrvD
{
	v_CB3* Data;
};

struct CrvP: public BaseAdjustment
{
	Spln* Mast;
	Spln* C1Sp;
	Spln* C2Sp;
	Spln* C3Sp;
	Spln* C4Sp;
	Spln* C5Sp;
	float Min_; /* NOLINT(readability-identifier-naming) */
	float Max_; /* NOLINT(readability-identifier-naming) */
};

struct CvHS: public BaseSubSel
{
	vector<array<int32_t, 2>> Hdls;
};

struct DCCm: public BaseCmd
{
	EnumT Labl;
};

struct DDFl
{
	FDsc* DBFD;
	FDsc* FBFD;
	FDsc* DPFD;
	FDsc* FPFD;
	GAtt* DGA_; /* NOLINT(readability-identifier-naming) */
	GAtt* DGAF;
};

struct DDef
{
	LDsc*          DLSD;
	LDsc*          FLSD;
	LDsc*          DBLS;
	FDsc*          DTFD;
	FDsc*          FTFD;
	FDsc*          DPFD;
	FDsc*          FPFD;
	FDsc*          DBFD;
	FDsc*          FBFD;
	BGrd*          DBLG;
	BGrd*          FBLG;
	DFFO*          DFFD;
	GAtt*          DGA_; /* NOLINT(readability-identifier-naming) */
	PAtt*          DPA_; /* NOLINT(readability-identifier-naming) */
	GAtt*          DGAF;
	PAtt*          DPAF;
	GAtt*          RGA_; /* NOLINT(readability-identifier-naming) */
	PAtt*          RPA_; /* NOLINT(readability-identifier-naming) */
	GAtt*          RGAF;
	PAtt*          RPAF;
	void*          TCGA;
	CFPa*          CTFP;
	vector<double> TFRC;
	vector<double> TFGW;
	bool           IgTW;
	bool           HOvr;
	bool           IgBG;
	double         TWBo[4];
	uint32_t       PFCT;
	EnumT          PFAn;
	SNAR*          SNPR;
	bool           SNPI;
	TbFt*          TbFm;
	vector<DDFl*>  Fill;
};

struct DFFO
{
	vector<void*> FKys;
	vector<void*> Fmts;
};

struct DHis
{
	uint32_t        Posi;
	vector<DcHI*>   Stac;
	vector<Rstr*>   RBa1;
	vector<RBMI*>   RBa3;
	vector<int32_t> RBaC;
	int32_t         SSHi;
};

struct DNCm: public BaseCmd
{
	bool Vald;
	/* ShpN*, Sprd* */
	vector<BaseLayer*> OldP;
	struct Sele*       OlSe;
	bool               CntA;
	bool               Ignr;
	bool               HasR;
	TxFU*              TxFl;
	bool               SFEM;
};

struct DPOp: public BaseProp
{
	uint8_t unit;
	EnumT   imgP;
	bool    tran;
	bool    face;
	bool    vert;
	bool    dblS;
	EnumT   Frmt;
	string  iccP;
	bool    cArt;
	double  wdth;
	double  hght;
	double  dpiV;
	double  vDPI;
	bool    incM;
	double  marL;
	double  marR;
	double  marT;
	double  marB;
	double  bldL;
	double  bldR;
	double  bldT;
	double  bldB;
	EnumT   PPTy;
};

struct DPro: public BaseCmd
{
	uint32_t                 Type;
	bool                     NRet;
	bool                     NPor;
	bool                     NTrn;
	bool                     NSHi;
	double                   NDPI;
	double                   NVDP;
	double                   NWid;
	double                   NHht;
	vector<array<double, 4>> NMar;
	vector<bool>             NPMr;
	double                   nbld[4];
	EnumT                    NFor;
	ICCP*                    NPro;
	uint8_t                  NUnt;
	bool                     NIMr;
	bool                     FPag;
	bool                     LftS;
	bool                     VStk;
	EnumT                    NIRP;
	bool                     ORet;
	bool                     OPor;
	bool                     OTrn;
	bool                     OSHi;
	double                   ODPI;
	double                   OVDP;
	double                   OWid;
	double                   OHht;
	vector<array<double, 4>> OMar;
	vector<bool>             OPMr;
	double                   obld[4];
	EnumT                    OFor;
	ICCP*                    OPro;
	uint8_t                  OUnt;
	bool                     OIMr;
	bool                     OFPg;
	bool                     OLfS;
	bool                     OVSt;
	EnumT                    OIRP;
	ForC*                    ConC;
	void*                    AssC;
	bool                     AssF;
	EnumT                    achT;
	vector<array<double, 6>> NewT;
	vector<void*>            RsCs;
	vector<void*>            OSBm;
	vector<void*>            NSBm;
	vector<double>           GdsH;
	vector<double>           GdsV;
	void*                    DPgC;
	void*                    APgC;
	void*                    MPCC;
	void*                    SMPC;
	int32_t                  FPSc;
	vector<void*>            DPCs;
	vector<void*>            APCs;
	vector<void*>            MPCs;
	vector<void*>            TfCs;
	vector<void*>            MDCs;
	vector<void*>            BDCs;
	EnumT                    Resa;
	bool                     RsRN;
	void*                    OBBR;
};

struct DcHI
{
	/* AAAC*, AAMC*, AARC*, ACCm*, AESC*, AOSC*, ARCm*, CRGl*, ChMA*, CmCm*, CrSl*, DCCm*, DNCm*, DPro*, EnBE*, EnCO*, EnGA*, EnGO*, EnIS*,
	 * EnIg*, EnOg*, EnPB*, EnSh*, EnSt*, ExIn*, FAFH*, FFCm*, FmTC*, GrMA*, GrNC*, InGl*, MC2C*, MvNC*, SBMC*, SDeC*, SLsC*, SSNS*, SSaC*,
	 * SViC*, SetE*, TrCm*, TrSl*, UANC*, XMgC*, XStC* */
	BaseCmd*      Cmnd;
	uint64_t      Tim2;
	vector<Futr*> Futu;
	BinaryData    Thum;
};

struct DcMD
{
	string                   XMPD;
	vector<array<double, 4>> AFRS;
	vector<int32_t>          AFIF;
	vector<int32_t>          AFSl;
	string                   FocM;
	string                   FocB;
	string                   FocP;
	string                   FocV;
	string                   COC_; /* NOLINT(readability-identifier-naming) */
	string                   HypF;
	string                   ExpB;
	string                   ISOE;
	string                   FocD;
	string                   Lens;
	string                   Auth;
	string                   SMBy;
	string                   MfBy;
	string                   Tags;
	string                   Cmnt;
	string                   Titl;
	string                   Revn;
	int64_t                  CrDt;
	int64_t                  SvDt;
	int64_t                  PtDt;
	int32_t                  SvCt;
	string                   FlNm;
	string                   Path;
	string                   Subj;
};

struct DeSy
{
	vector<void*>  UDMC;
	vector<void*>  RDMC;
	vector<void*>  UDNC;
	vector<void*>  RDDC;
	vector<void*>  UDGN;
	vector<void*>  RDGN;
	bool           cnmi;
	EnumT          unrc;
	bool           dtid;
	vector<string> olgd;
	vector<ShpN*>  Fir3;
	vector<PSRe*>  Sec3;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir4;
	vector<PSRe*>      Sec4;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir6;
	vector<PSRe*>      Sec6;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir7;
	vector<PSRe*>      Sec7;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fir1;
	vector<PSRe*>      Sec1;
	/* Grup*, PCrv*, Scop*, ShpN* */
	vector<BaseLayer*> Fr10;
	vector<PSRe*>      Sc10;
	/* Grup*, PCrv*, Scop*, ShpN* */
	vector<BaseLayer*> Fr12;
	vector<PSRe*>      Sc12;
	/* Grup*, PCrv*, Scop*, ShpN* */
	vector<BaseLayer*> Fr11;
	vector<PSRe*>      Sc11;
	vector<PCrv*>      Fir8;
	vector<PSRe*>      Sec8;
	vector<void*>      Fir9;
	vector<void*>      Sec9;
	vector<void*>      Fir5;
	vector<void*>      Sec5;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr14;
	vector<PSRe*>      Sc14;
	vector<void*>      Fr16;
	vector<void*>      Sc16;
	vector<void*>      Fr25;
	vector<void*>      Sc25;
	vector<void*>      Fr17;
	vector<void*>      Sc17;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Fr18;
	vector<PSRe*>      Sc18;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr19;
	vector<PSRe*>      Sc19;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr13;
	vector<PSRe*>      Sc13;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr21;
	vector<PSRe*>      Sc21;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr22;
	vector<PSRe*>      Sc22;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Fr23;
	vector<PSRe*>      Sc23;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr24;
	vector<PSRe*>      Sc24;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Fr26;
	vector<PSRe*>      Sc26;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	vector<BaseLayer*> Fr15;
	vector<PSRe*>      Sc15;
	vector<void*>      lnkd;
	vector<void*>      ulkd;
	struct Sele*       Sele;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer*    Layr;
	EnumT         Dire;
	bool          Prev;
	bool          ArtC;
	bool          AAtC;
	bool          CArC;
	vector<void*> mapo;
};

struct DecP
{
	int32_t Mask;
	LDsc*   LinS;
	FDsc*   BruS;
	FDsc*   PenS;
	FDsc*   Tran;
	double  Indt[4];
	int32_t RLft;
	int32_t RTop;
	int32_t RRgt;
	int32_t RBot;
	bool    CmBx;
};

struct Deco: public BaseAtt
{
	vector<DecP*> Deco;
};

struct DocN
{
	int32_t        TrCn;
	EnumT          TrAn;
	double         TrFP[2];
	bool           TrFV;
	EnumT          Blnd;
	bool           PasT;
	BlnR*          BlRa;
	double         SrBx[4];
	double         SrPB[4];
	string         Desc;
	string         DefD;
	void*          TagC;
	bool           Visi;
	float          Opac;
	float          FOpc;
	vector<void*>  FiEf;
	bool           Edtb;
	bool           CEdb;
	bool           MEtb;
	void*          Data;
	vector<string> Frst;
	vector<string> Scnd;
	EnumT          Hyty;
	string         Hypr;
	EnumT          HyTr;
	EnumT          TWSt;
	double         TWBo[4];
	EnumT          CLiT;
	vector<Sprd*>  Chld;
	vector<Sprd*>  MpCh;
	uint32_t       BFCr;
	vector<FDsc*>  BFFl;
	uint32_t       LICr;
	vector<LDsc*>  LILn;
	vector<FDsc*>  LIFl;
	BGrd*          Opts;
	float          DORT;
	double         DfSz[2];
	bool           FcPa;
	bool           LPSt;
	bool           VtSt;
	DcMD*          DCMD;
	vector<DocS*>  DSec;
	vector<VwPD*>  VPts;
	FTXR*          FTxR;
	struct Indx*   Indx;
	int32_t        TraC;
};

struct DocS
{
	uint32_t StId;
	int32_t  NbFr;
	string   Name;
	EnumT    Frmt;
};

struct DrCp: public BaseAtt
{
	int32_t Heit;
	bool    Left;
	bool    SDsc;
};

struct DrpD: public BaseDels
{
};

struct Dupl
{
	vector<void*> UndR;
	bool          Link;
	SpRV*         IRec;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> Undo;
	/* PCrv*, ShpN* */
	vector<BaseLayer*> UndL;
	vector<void*>      Redo;
	vector<void*>      RedL;
	struct Sele*       NewS;
	struct Sele*       OldS;
	double             Trns[6];
	bool               ObRS;
	bool               ASnC;
	bool               MdSp;
	bool               MdTc;
	vector<void*>      Fir3;
	vector<void*>      Sec3;
	vector<void*>      Fir4;
	vector<void*>      Sec4;
	vector<void*>      Fir6;
	vector<void*>      Sec6;
	vector<void*>      Fir7;
	vector<void*>      Sec7;
	vector<void*>      Fir1;
	vector<void*>      Sec1;
	vector<void*>      Fr10;
	vector<void*>      Sc10;
	vector<void*>      Fr12;
	vector<void*>      Sc12;
	vector<void*>      Fr11;
	vector<void*>      Sc11;
	vector<void*>      Fir8;
	vector<void*>      Sec8;
	vector<void*>      Fir9;
	vector<void*>      Sec9;
	vector<void*>      Fir5;
	vector<void*>      Sec5;
	vector<void*>      Fr14;
	vector<void*>      Sc14;
	vector<void*>      Fr16;
	vector<void*>      Sc16;
	vector<void*>      Fr25;
	vector<void*>      Sc25;
	vector<void*>      Fr17;
	vector<void*>      Sc17;
	vector<void*>      Fr18;
	vector<void*>      Sc18;
	vector<void*>      Fr19;
	vector<void*>      Sc19;
	vector<void*>      Fr13;
	vector<void*>      Sc13;
	vector<void*>      Fr21;
	vector<void*>      Sc21;
	vector<void*>      Fr22;
	vector<void*>      Sc22;
	vector<void*>      Fr23;
	vector<void*>      Sc23;
	vector<void*>      Fr24;
	vector<void*>      Sc24;
	vector<void*>      Fr26;
	vector<void*>      Sc26;
	vector<void*>      Fr15;
	vector<void*>      Sc15;
	vector<void*>      lnkd;
	vector<ShpN*>      ulkd;
	struct Sele*       Sele;
	/* Scop*, ShpN* */
	BaseLayer* Layr;
	EnumT      Dire;
	bool       Prev;
	bool       ArtC;
	bool       AAtC;
	bool       CArC;
	/* PCrv*, ScPr*, ShpN* */
	vector<BaseLayer*> mapo;
};

struct DyBm: public BaseBitm
{
	EnumT           Frmt;
	int32_t         BmpW;
	int32_t         BmpH;
	EmbeddedData    Bckg;
	ICC*            Prof;
	bool            DelA;
	EnumT           MipM;
	int32_t         LInf;
	int32_t         TInf;
	vector<Blck*>   Idx1;
	vector<uint8_t> Sta1;
	vector<Blck*>   Idx2;
	vector<uint8_t> Sta2;
	vector<Blck*>   Idx3;
	vector<uint8_t> Sta3;
	vector<Blck*>   Idx4;
	vector<uint8_t> Sta4;
	vector<Blck*>   Idx5;
	vector<uint8_t> Sta5;
	vector<Blck*>   MI1_1;
	vector<uint8_t> MT1_1;
	vector<Blck*>   MI2_1;
	vector<uint8_t> MT2_1;
	vector<Blck*>   MI3_1;
	vector<uint8_t> MT3_1;
	vector<Blck*>   MI4_1;
	vector<uint8_t> MT4_1;
	vector<Blck*>   MI5_1;
	vector<uint8_t> MT5_1;
	vector<Blck*>   MI1_2;
	vector<uint8_t> MT1_2;
	vector<Blck*>   MI2_2;
	vector<uint8_t> MT2_2;
	vector<Blck*>   MI3_2;
	vector<uint8_t> MT3_2;
	vector<Blck*>   MI4_2;
	vector<uint8_t> MT4_2;
	vector<Blck*>   MI5_2;
	vector<uint8_t> MT5_2;
	vector<Blck*>   MI1_3;
	vector<uint8_t> MT1_3;
	vector<Blck*>   MI2_3;
	vector<uint8_t> MT2_3;
	vector<Blck*>   MI3_3;
	vector<uint8_t> MT3_3;
	vector<Blck*>   MI4_3;
	vector<uint8_t> MT4_3;
	vector<Blck*>   MI5_3;
	vector<uint8_t> MT5_3;
	vector<Blck*>   MI1_4;
	vector<uint8_t> MT1_4;
	vector<Blck*>   MI2_4;
	vector<uint8_t> MT2_4;
	vector<Blck*>   MI3_4;
	vector<uint8_t> MT3_4;
	vector<Blck*>   MI4_4;
	vector<uint8_t> MT4_4;
	vector<Blck*>   MI5_4;
	vector<uint8_t> MT5_4;
	vector<Blck*>   MI1_5;
	vector<uint8_t> MT1_5;
	vector<Blck*>   MI2_5;
	vector<uint8_t> MT2_5;
	vector<Blck*>   MI3_5;
	vector<uint8_t> MT3_5;
	vector<Blck*>   MI4_5;
	vector<uint8_t> MT4_5;
	vector<Blck*>   MI5_5;
	vector<uint8_t> MT5_5;
	vector<Blck*>   MI1_6;
	vector<uint8_t> MT1_6;
	vector<Blck*>   MI2_6;
	vector<uint8_t> MT2_6;
	vector<Blck*>   MI3_6;
	vector<uint8_t> MT3_6;
	vector<Blck*>   MI4_6;
	vector<uint8_t> MT4_6;
	vector<Blck*>   MI5_6;
	vector<uint8_t> MT5_6;
	vector<Blck*>   MI1_7;
	vector<uint8_t> MT1_7;
	vector<Blck*>   MI1_8;
	vector<uint8_t> MT1_8;
	vector<Blck*>   MI2_8;
	vector<uint8_t> MT2_8;
	vector<Blck*>   MI3_8;
	vector<uint8_t> MT3_8;
	vector<Blck*>   MI4_8;
	vector<uint8_t> MT4_8;
	vector<Blck*>   MI5_8;
	vector<uint8_t> MT5_8;
	vector<Blck*>   MI1_9;
	vector<uint8_t> MT1_9;
	vector<Blck*>   MI2_9;
	vector<uint8_t> MT2_9;
	vector<Blck*>   MI3_9;
	vector<uint8_t> MT3_9;
	vector<Blck*>   MI4_9;
	vector<uint8_t> MT4_9;
	vector<Blck*>   MI5_9;
	vector<uint8_t> MT5_9;
	vector<Blck*>   MI1_10;
	vector<uint8_t> MT1_10;
	vector<Blck*>   MI2_10;
	vector<uint8_t> MT2_10;
	vector<Blck*>   MI3_10;
	vector<uint8_t> MT3_10;
	vector<Blck*>   MI4_10;
	vector<uint8_t> MT4_10;
	vector<Blck*>   MI5_10;
	vector<uint8_t> MT5_10;
	vector<Blck*>   MI1_11;
	vector<uint8_t> MT1_11;
	vector<Blck*>   MI2_11;
	vector<uint8_t> MT2_11;
	vector<Blck*>   MI3_11;
	vector<uint8_t> MT3_11;
	vector<Blck*>   MI4_11;
	vector<uint8_t> MT4_11;
	vector<Blck*>   MI1_12;
	vector<uint8_t> MT1_12;
	vector<Blck*>   MI2_12;
	vector<uint8_t> MT2_12;
	vector<Blck*>   MI3_12;
	vector<uint8_t> MT3_12;
	vector<Blck*>   MI4_12;
	vector<uint8_t> MT4_12;
	vector<void*>   MI1_13;
	vector<uint8_t> MT1_13;
	vector<void*>   MI2_13;
	vector<uint8_t> MT2_13;
	vector<void*>   MI3_13;
	vector<uint8_t> MT3_13;
	vector<Blck*>   MI4_13;
	vector<uint8_t> MT4_13;
	vector<void*>   MI1_14;
	vector<uint8_t> MT1_14;
	vector<void*>   MI2_14;
	vector<uint8_t> MT2_14;
	vector<void*>   MI3_14;
	vector<uint8_t> MT3_14;
	vector<void*>   MI4_14;
	vector<uint8_t> MT4_14;
	vector<Blck*>   MI2_7;
	vector<uint8_t> MT2_7;
	vector<Blck*>   MI3_7;
	vector<uint8_t> MT3_7;
	vector<Blck*>   MI4_7;
	vector<uint8_t> MT4_7;
	vector<Blck*>   MI5_7;
	vector<uint8_t> MT5_7;
};

struct EDfP
{
	double  RadX;
	double  RadY;
	double  InFo;
	double  Rota;
	double  Cent[2];
	double  Radi;
	int32_t Vibr;
	double  Clar;
};

struct EOEp: public BaseExport
{
	int32_t Qlty;
	int32_t PSLv;
	bool    MnSz;
};

struct EOGf: public BaseExport
{
};

struct EOHD: public BaseExport
{
};

struct EOJp: public BaseExport
{
	uint8_t Qlty;
	bool    Prog;
	bool    E2Ph;
};

struct EOPS: public BaseExport
{
	bool  comp;
	bool  smll;
	bool  fltn;
	EnumT grad;
	EnumT adju;
	EnumT effc;
	EnumT line;
	EnumT blnd;
};

struct EOPd: public BaseExport
{
	int32_t Qlty;
	EnumT   CoSp;
	EnumT   EmFo;
	bool    SubF;
	bool    AAdv;
	bool    Spot;
	bool    OvPB;
	bool    EHyp;
	bool    ELay;
	bool    CnvI;
	bool    IPrM;
	bool    PMCB;
	bool    PMRM;
	bool    PMCM;
	bool    PMPI;
};

struct EOPn: public BaseExport
{
};

struct EOSv: public BaseExport
{
	int32_t Qlty;
	bool    arco;
	bool    flat;
	bool    cutp;
	bool    isvb;
	bool    newl;
	bool    ltxp;
};

struct EOTf: public BaseExport
{
	EnumT TifC;
};

struct EOTg: public BaseExport
{
};

struct EOXR: public BaseExport
{
	bool LyMd;
	bool CSFF;
	bool v_32Im;
	bool v_32Sp;
	bool v_32Ot;
	bool IULT;
};

struct EmbC
{
	string       File;
	bool         Link;
	EmbeddedData EmbC;
};

struct EmbN: public BaseLayer
{
	EmbC*   EmCn;
	int32_t back;
	EnumT   PBBx;
	string  EmSp;
	bool    EmAC;
	int32_t SIdx;
	bool    IsMs;
	int32_t AIdx;
};

struct EmbR: public BaseBitm
{
	EmbC*   EmCn;
	int32_t back;
	EnumT   PBBx;
	string  EmSp;
	bool    EmAC;
};

struct EnBE: public BaseCmd
{
};

struct EnCO: public BaseCmd
{
};

struct EnGA: public BaseCmd
{
};

struct EnGO: public BaseCmd
{
};

struct EnIS: public BaseCmd
{
};

struct EnIg: public BaseCmd
{
};

struct EnOg: public BaseCmd
{
};

struct EnPB: public BaseCmd
{
};

struct EnSh: public BaseCmd
{
};

struct EnSt: public BaseCmd
{
};

struct ExBB
{
	vector<ExBF*> Chks;
};

struct ExBF
{
	bool          RtOy;
	EnumT         Srch;
	EnumT         ORul;
	string        FNme;
	string        Head;
	string        Foot;
	vector<Sctn*> Scts;
};

struct ExCI: public BaseExCsts
{
	int32_t min;
	int32_t max;
};

struct ExCS
{
	/* ExCI*, ExCt* */
	vector<BaseExCsts*> csts;
};

struct ExCV
{
	ExCS* CSet;
	/* ExV2*, ExVI*, ExVR* */
	vector<BaseExVals*> vals;
};

struct ExCm
{
	/* EOEp*, EOGf*, EOHD*, EOJp*, EOPS*, EOPd*, EOPn*, EOSv*, EOTf*, EOTg*, EOXR* */
	BaseExport*   ExOp;
	vector<Scal*> Scls;
};

struct ExCt: public BaseExCsts
{
};

struct ExEq
{
	string eqtn;
};

struct ExIn: public BaseCmd
{
	bool         Incl;
	vector<bool> Undo;
};

struct ExRA: public BaseLayer
{
};

struct ExRS
{
	Rec* v_1x;
	Rec* v_2x;
	Rec* v_3x;
};

struct ExSc
{
	EnumT  SzTy;
	double Size;
	double Mult;
};

struct ExV2: public BaseExVals
{
	double val[2];
};

struct ExVI: public BaseExVals
{
	int32_t val;
};

struct ExVR: public BaseExVals
{
	double val;
};

struct ExpP: public BaseAdjustment
{
	float Expo;
	bool  Lega;
};

struct FAFH: public BaseCmd
{
	double        Alph;
	uint32_t      Cont;
	vector<FDsc*> OldF;
	bool          LSSl;
};

struct FDsc: public BaseFill
{
	/* FilG*, FilN*, FilS* */
	BaseFill* FDeF;
	double    FDeX[6];
};

struct FExO: public BaseExport
{
	EnumT   FTyp;
	EnumT   BSFm;
	uint8_t Qlty;
};

struct FFCm: public BaseCmd
{
	double Poin[2];
	/* CMYK*, GRAY*, HSLA*, LABA*, RGBA* */
	BaseColor* Colo;
	bool       Cont;
	EnumT      SamS;
	EnumT      BleM;
	bool       AbrP;
	float      PMin;
	float      PMax;
};

struct FRst: public BaseLayer
{
};

struct FSDe: public BaseDels
{
	Font*   Font;
	int32_t Flds;
};

struct FTXR
{
	vector<string> lngs;
	vector<string> txts;
};

struct FilG: public BaseFill
{
	EnumT Type;
	Grad* Grad;
	bool  XCor;
};

struct FilN: public BaseFill
{
};

struct FilS: public BaseFill
{
	/* CMYK*, GRAY*, HSLA*, LABA*, Pant*, RGBA*, RegC* */
	BaseColor* Colr;
	bool       RClK;
};

struct Filp: public BaseProp
{
	/* FilG*, FilN*, FilS* */
	BaseFill* FLsc;
};

struct FlRN: public BaseLayer
{
	/* Clar*, Clrt*, RDF2*, RGBC*, RHPC*, RLdC*, RLig*, RUSC*, RVgC* */
	BaseFilt* Filt;
	bool      ProA;
};

struct FlrG: public BaseGlys
{
	int32_t ScBg;
	int32_t FiTy;
	int32_t FStr;
};

struct FmTC: public BaseCmd
{
	/* GASD*, PADS* */
	BaseDels*     Delt;
	EnumT         TDfT;
	bool          UPGE;
	bool          IgTX;
	bool          USty;
	PaAS*         OldP;
	SSAS*         OldS;
	PaAS*         NewP;
	GlAS*         NewG;
	vector<Stop*> OItm;
};

struct FntM
{
	vector<void*> Pair;
};

struct Font
{
	string       Post;
	string       Famy;
	int32_t      Wegt;
	bool         Ital;
	int32_t      Widh;
	struct Pano* Pano;
};

struct ForC: public BaseCmd
{
	EnumT         NewF;
	EnumT         OldF;
	ICCP*         NRGB;
	ICCP*         NCMY;
	ICCP*         NIAP;
	ICCP*         NLAB;
	ICCP*         ORGB;
	ICCP*         OCMY;
	ICCP*         OIAP;
	ICCP*         OLAB;
	vector<DyBm*> OldB;
	vector<DyBm*> OlCB;
	vector<void*> NeCB;
	vector<FDsc*> OlFl;
	vector<void*> NeFl;
	/* HSLA*, RGBA* */
	vector<BaseColor*> OlCl;
	vector<void*>      NeCl;
	vector<GAtt*>      OlGl;
	vector<PAtt*>      OlPr;
	bool               NFrC;
	bool               NTBF;
	TStS*              OTSt;
	TStS*              NTSt;
};

struct Futr
{
	vector<DcHI*> Itms;
};

struct GADD: public BaseDels
{
	double Valu;
};

struct GAID: public BaseDels
{
	int32_t Valu;
};

struct GAOD: public BaseDels
{
	/* FDsc*, HlkA*, LDsc*, OpAA*, OtAt* */
	BaseFill* Valu;
};

struct GASD: public BaseDels
{
	string Valu;
};

struct GAtt
{
	vector<int32_t> Ints;
	vector<double>  Doub;
	vector<string>  Stri;
	/* FDsc*, HlkA*, LDsc*, OpAA*, OtAt* */
	vector<BaseFill*> Objs;
	Font*             DFnt;
	Font*             RFnt;
};

struct GRAY: public BaseColor
{
	ColorGRAY v_col;
};

struct GSSP
{
	/* BrGl*, FlrG*, LLGl*, PgNG* */
	vector<BaseGlys*> Glys;
	string            Utf8;
};

struct GStr
{
	string        Utf8;
	vector<GSSP*> Mixd;
};

struct Gaus: public BaseEffect
{
	bool PrAl;
};

struct GlAR
{
	int32_t Indx;
	GAtt*   Item;
};

struct GlAS
{
	vector<GlAR*> Runs;
};

struct GrMA: public BaseCmd
{
	vector<GrMP*> OldP;
};

struct GrMP: public BaseAdjustment
{
	vector<float> GrCD;
	vector<float> GrPD;
};

struct GrNC: public BaseCmd
{
	Grup* Grou;
	/* Scop*, Sprd* */
	vector<BaseLayer*> OldP;
	/* Grup*, Rstr* */
	vector<BaseLayer*>       OldS;
	struct Sele*             OlSl;
	vector<EnumT>            OlCT;
	vector<array<double, 6>> OlTr;
	bool                     NCmG;
	bool                     RACn;
};

struct GrRA: public BaseLayer
{
};

struct Grad
{
	vector<array<double, 2>> Posn;
	/* CMYK*, GRAY*, HSLA*, LABA*, Pant*, RGBA* */
	vector<BaseColor*> Cols;
};

struct GrdO: public BaseEffect
{
};

struct Grup: public BaseLayer
{
};

struct HSLA: public BaseColor
{
	ColorHSLA v_col;
};

struct HSSP: public BaseAdjustment
{
	float         HueA;
	float         SatA;
	float         LumA;
	vector<float> HueC;
	vector<float> SatC;
	vector<float> LumC;
	vector<float> RngC;
	bool          HSV;
};

struct HlkA: public BaseFill
{
	void* Data;
};

struct HsRA: public BaseLayer
{
};

struct IBRB: public BaseBrush
{
};

struct ICC
{
	ICCP* RGBP;
	ICCP* RGUP;
	ICCP* CMYP;
	ICCP* IAPr;
	ICCP* LABP;
	EnumT Intn;
	bool  BPCm;
};

struct ICCP
{
	BinaryData Data;
};

struct ILDO
{
	/* PCrv*, ShpN* */
	vector<BaseLayer*> ILOb;
};

struct ILGI
{
	/* CnsN*, Comp*, Grup*, MPIN*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, Sprd*, TxtA*, TxtF* */
	vector<BaseLayer*> ILOb;
};

struct ILSN
{
	/* CnsN*, Comp*, Grup*, MPIN*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, Sprd*, TxtA*, TxtF* */
	vector<BaseLayer*> ILOb;
};

struct ILTI
{
	/* CnsN*, Comp*, Grup*, MRst*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, TxtF* */
	vector<BaseLayer*> ILOb;
};

struct ILTf
{
	vector<TxFl*> ILOb;
};

struct ImgN: public BaseLayer
{
	EnumT        ExtT;
	EnumT        ResT;
	string       StkU;
	string       uPro;
	string       StAu;
	int32_t      ODPI;
	string       ICCP;
	EmbeddedData Orig;
};

struct InGl: public BaseCmd
{
	bool         TSel;
	bool         Togl;
	bool         PrNc;
	struct Sele* OldS;
};

struct InRA: public BaseLayer
{
};

struct Indx
{
	vector<void*> Tpcs;
	vector<void*> OrTp;
	string        Sort;
	string        Lang;
	bool          InSH;
	bool          GpPR;
	bool          ExpX;
	string        SAfT;
	string        SBtI;
	string        SBtR;
	string        SBfX;
	string        SSee;
	string        SSeA;
	string        SAfX;
};

struct InnG: public BaseEffect
{
	bool Cntr;
};

struct InnS: public BaseEffect
{
};

struct LABA: public BaseColor
{
	ColorLABA v_col;
};

struct LDsc: public BaseFill
{
	LSty*   LDeL;
	bool    LDBe;
	bool    LDSc;
	CrvD*   LDeP;
	int32_t LDSa;
	bool    LIAh;
};

struct LLGl: public BaseGlys
{
	int32_t Levl;
};

struct LR3D
{
	EmbeddedData  Blob;
	int32_t       Dime;
	vector<float> Pxls;
	string        Name;
};

struct LStr
{
	string Str_; /* NOLINT(readability-identifier-naming) */
	string Ctxt;
};

struct LSty
{
	curve12_t Data;
	double    Wght;
	/* BmRB*, IBRB*, RRBr* */
	BaseBrush*     Brus;
	double         Phse;
	vector<double> Patn;
};

struct Layt
{
	/* ArFr*, CoFr* */
	vector<BaseFrms*> Frms;
};

struct LeFP: public BaseAdjustment
{
	uint16_t L_; /* NOLINT(readability-identifier-naming) */
	uint16_t A_; /* NOLINT(readability-identifier-naming) */
	uint16_t B_; /* NOLINT(readability-identifier-naming) */
	float    Dens;
	bool     Pres;
};

struct LeRA: public BaseLayer
{
};

struct LevP: public BaseAdjustment
{
	float         Blac;
	float         Whit;
	float         OutB;
	float         OutW;
	vector<float> BlkC;
	vector<float> WhtC;
	vector<float> GamC;
	vector<float> OBlC;
	vector<float> OWhC;
};

struct LigP
{
	double        Ambi;
	double        Diff;
	double        Spec;
	double        Expo;
	RGBA*         AmbC;
	HSLA*         SpeC;
	double        Dept;
	void*         BMap;
	bool          ScaX;
	bool          ScaY;
	double        BMOp;
	vector<LigS*> Lits;
};

struct LigS
{
	EnumT  Type;
	RGBA*  Colo;
	double Spin;
	double Tilt;
	double Cent[2];
	double Dist;
	double OCon;
	double ICon;
};

struct LisA: public BaseAtt
{
	EnumT          Type;
	int32_t        Id;
	int32_t        Levl;
	vector<double> IStr;
	double         ITxt;
	GStr*          Strn;
	GStr*          Sepr;
	double         Scal;
	double         OffY;
	EnumT          Alig;
	EnumT          NFmt;
	int32_t        Strt;
	bool           Tier;
	double         ITab;
	GStr*          BulS;
	GStr*          NumS;
	EnumT          ResT;
	int32_t        ResL;
};

struct LoDO
{
	int32_t         Page;
	bool            IFET;
	bool            TxGr;
	FntM*           FoMp;
	double          dpi;
	EnumT           ClSp;
	vector<int32_t> Pags;
};

struct MC2C: public BaseCmd
{
	double        Delt[2];
	double        Dlt2[2];
	bool          SOcr;
	bool          Clos;
	bool          ClSt;
	vector<Undo*> Undo;
	vector<void*> OCrv;
	void*         ORCv;
	struct Sele*  OldS;
	bool          OmLN;
};

struct MPIN: public BaseLayer
{
	uint32_t PgOf;
	uint32_t MPOf;
	uint32_t PgCt;
	EnumT    ScMd;
};

struct MRst: public BaseLayer
{
};

struct MacI
{
	/* ARCm*, CMTC*, ClrX*, ForC*, MgDC* */
	BaseCmd*         Cmd;
	bool             Enab;
	double           Sprd[4];
	vector<uint64_t> FavP;
	vector<uint64_t> MUID;
	vector<void*>    MSpl;
};

struct MacP: public BaseProp
{
	Macr* Macr;
};

struct Macr
{
	vector<MacI*> Macr;
	string        Desc;
};

struct Matx
{
	int32_t        Rows;
	int32_t        Cols;
	vector<double> Data;
};

struct MgDC: public BaseCmd
{
	void* SrcN;
	void* DstN;
	void* OldS;
	void* OldP;
	void* OlSi;
	void* Cach;
	bool  Freq;
};

struct MvNC: public BaseCmd
{
	EnumT Type;
	EnumT CLiT;
	/* Grup*, Rstr*, Scop*, ShpN* */
	BaseLayer* Dest;
	/* Grup*, Scop*, ShpN*, Sprd* */
	vector<BaseLayer*> OldP;
	vector<EnumT>      OldC;
	bool               RACt;
	vector<bool>       OlTS;
	bool               FrKA;
	/* Grup*, Rstr*, Scop*, ShpN*, Sprd* */
	vector<BaseLayer*> DtLO;
	vector<bool>       DtLF;
};

struct OCRN: public BaseLayer
{
};

struct OSty: public BaseProp
{
	ObjS* OSty;
};

struct OTFD: public BaseDels
{
	vector<UndR*> Feat;
	bool          cler;
	LStr*         LDsc;
};

struct OTFS
{
	uint32_t Feat;
	int32_t  Valu;
};

struct ObSB
{
	EnumT         Cont;
	uint32_t      BFCr;
	vector<FDsc*> BFFl;
	/* FDsc*, FilS* */
	BaseFill* BFil;
};

struct ObSL
{
	EnumT         Cont;
	uint32_t      LICr;
	vector<LDsc*> LILn;
	vector<FDsc*> LIFl;
	LDsc*         LSty;
	/* FDsc*, FilS* */
	BaseFill* PFil;
};

struct ObST
{
	EnumT Cont;
};

struct ObjS: public BaseLayer
{
	bool  HsFE;
	bool  HsBM;
	bool  HsVi;
	bool  HsTW;
	bool  HsDO;
	EnumT Frmt;
	ICCP* RGBP;
	void* CMYK;
	ObSB* MBru;
	ObSL* MLin;
	ObST* MTra;
	ObSL* FLin;
	ObSB* FBru;
	ObST* FTra;
	void* GlyA;
	void* ParA;
	bool  OSNE;
	bool  HsPF;
	void* SNPR;
};

struct OpAA: public BaseFill
{
	vector<OpAV*> Vals;
};

struct OpAV
{
	string Glyp;
	double Left;
};

struct OtAt: public BaseFill
{
	vector<OTFS*> Setn;
};

struct OutG: public BaseEffect
{
};

struct PADD: public BaseDels
{
	double Valu;
};

struct PADS: public BaseDels
{
	string Valu;
};

struct PAID: public BaseDels
{
	int32_t Valu;
};

struct PAOD: public BaseDels
{
	/* Deco*, LisA*, TabS* */
	BaseAtt* Valu;
};

struct PAtt
{
	vector<int32_t> Ints;
	vector<double>  Doub;
	vector<string>  Stri;
	/* AFAt*, Deco*, DrCp*, LisA*, TabS*, TocA* */
	vector<BaseAtt*> Objs;
};

struct PBxR
{
	vector<array<double, 4>> rcts;
};

struct PCFl
{
	uint32_t MUID;
	int64_t  MChk;
	int64_t  UChk;
	uint32_t NUID;
	PTNd*    Root;
};

struct PCrv: public BaseLayer
{
	PCrv* MCrM;
};

struct PCvD
{
	v_CB1* Data;
	v_CB2* CnrD;
};

struct PLef
{
	string   Name;
	string   ONam;
	string   DNam;
	uint32_t v_UID;
	uint32_t OUID;
	/* ACrt*, AbMp*, Adjs*, AstP*, Brus*, CrPP*, DPOp*, Filp*, MacP*, OSty*, PTCP*, PfPr*, SGrP*, SPPp*, TExM*, TonP* */
	BaseProp* Prop;
};

struct PLiA
{
	vector<PLig*> PLis;
};

struct PLig
{
	double Alph;
	double Beta;
	HSLA*  Colo;
};

struct PNoC: public BaseCmd
{
	EnumT        Form;
	ICCP*        RGBS;
	ICCP*        CMYS;
	ICCP*        IA_S;
	ICCP*        LABS;
	double       VPRc[4];
	bool         Tagg;
	void*        DCmd;
	void*        TCmd;
	struct Sele* OSel;
	double       OCRc[4];
	struct Sele* OldS;
};

struct PRNS: public BaseCmd
{
};

struct PSRe
{
	void* Mstr;
	void* FSlv;
};

struct PTCP: public BaseProp
{
	PTCf*         Cnfg;
	vector<Prst*> Prst;
};

struct PTCf
{
	vector<PTEq*> eqns;
	ExCS*         cnst;
	EnumT         cfmt;
	bool          rads;
};

struct PTEq
{
	ExEq*    eqtn;
	uint32_t mask;
};

struct PTNd
{
	uint32_t      CUID;
	uint32_t      Usge;
	uint32_t      v_UID;
	uint32_t      OUID;
	string        Name;
	string        ONam;
	string        DNam;
	vector<PLef*> Levs;
	vector<PTNd*> Chld;
	uint32_t      CIdx;
};

struct PTRt
{
	uint32_t NUID;
	PTNd*    Root;
};

struct PaAR
{
	int32_t Indx;
	PAtt*   Item;
};

struct PaAS
{
	vector<PaAR*> Runs;
};

struct PaFr: public BaseFrms
{
	PCvD*          PCrv;
	vector<bool>   Revr;
	vector<double> Strt;
	vector<double> Ends;
	vector<double> Advc;
};

struct Pano
{
	vector<uint8_t> byte;
};

struct Pant: public BaseColor
{
	/* HSLA*, LABA*, RGBA* */
	BaseColor* base;
	RGBA*      srgb;
	bool       ispt;
	string     name;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct Per_42
{
	vector<Quad*> Pers;
	int32_t       Curr;
};

struct Pers
{
	ApVs* OVer;
	ApVs* NVer;
	DocN* DocR;
	Sprd* EdRt;
	Sele* CSel;
	Sele* SlBQ;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer*    CLyr;
	SRst*         RasS;
	vector<Grup*> Symb;
	/* FilG*, FilN*, FilS* */
	vector<BaseFill*> RFll;
	PTRt*             DFll;
	DDef*             DDFl;
	vector<CrvD*>     PrPr;
	bool              v_32Un;
	string            OCIO;
	string            OCIV;
	/* EOJp*, EOPS*, EOPn*, EOSv*, FExO* */
	BaseExport*   DFEO;
	string        XMPM;
	struct UVCn*  UVCn;
	uint8_t       UntT;
	EnumT         DDRF;
	bool          EdAL;
	bool          CCFm;
	bool          PrCC;
	bool          PrFC;
	ICCP*         IAPr;
	ICCP*         CMYP;
	ICCP*         LABP;
	ICCP*         RGBP;
	ICCP*         RGUP;
	EnumT         Intn;
	bool          BPCm;
	uint8_t       SnUT;
	bool          USnG;
	SnpG*         SGrd;
	bool          VRul;
	bool          LGui;
	bool          VAll;
	bool          VGui;
	bool          VMar;
	bool          VBld;
	bool          VGrd;
	bool          VTxF;
	bool          VBlG;
	int32_t       BlGT;
	uint64_t      TxVO;
	bool          VSpl;
	bool          ClSp;
	bool          VCGu;
	PTRt*         PrpC;
	vector<GStr*> SpIg;
	struct ExRS*  ExRS;
	TStS*         TSty;
	TBFR*         TFmR;
	TBSO*         TSrO;
	LoDO*         LoOp;
	vector<void*> Snap;
	void*         CurS;
	int32_t       Indx;
	vector<void*> SprC;
	bool          Rest;
	bool          DcSH;
	DHis*         Hist;
	struct Macr*  Macr;
	DcMD*         DCMD;
	ExBB*         EBDB;
	EnumT         IRPC;
	uint64_t      IRNL;
	EnumT         PPTy;
	EnumT         PfTg;
	PfPr*         PfPl;
};

struct PfPr: public BaseProp
{
	string           name;
	vector<uint32_t> idsl;
};

struct PfRA: public BaseLayer
{
};

struct PgNG: public BaseGlys
{
	int32_t Type;
};

struct PhgB: public BaseEffect
{
	double Ambi;
	double Diff;
	double Spec;
	double Expo;
	HSLA*  AmbC;
	HSLA*  SpeC;
	PLiA*  Lits;
};

struct PoRA: public BaseLayer
{
};

struct PosP: public BaseAdjustment
{
	int32_t Post;
};

struct Pref
{
	vector<string>  BKey;
	vector<bool>    BVal;
	vector<string>  DKey;
	vector<double>  DVal;
	vector<string>  IKey;
	vector<int32_t> IVal;
	vector<string>  PKey;
	/* IBRB*, RRBr* */
	vector<BaseBrush*> PVal;
};

struct Prst
{
	string Name;
	ExCV*  Vals;
};

struct PthT
{
	string Path;
};

struct Quad
{
	double X0;
	double X1;
	double X2;
	double X3;
	double Y0;
	double Y1;
	double Y2;
	double Y3;
};

struct RBMI
{
	DyBm*   Bitm;
	string  Desc;
	bool    Auth;
	int32_t LOff;
	int32_t TOff;
};

struct RDF2: public BaseFilt
{
	EDfP* Para;
};

struct RGBA: public BaseColor
{
	ColorRGBA v_col;
};

struct RGBC: public BaseFilt
{
};

struct RHPC: public BaseFilt
{
	bool Mono;
};

struct RLdC: public BaseFilt
{
	double Inte;
	double Orig[2];
	double RadX;
	double RadY;
};

struct RLig: public BaseFilt
{
	LigP* lpar;
};

struct RRBr: public BaseBrush
{
};

struct RRFC: public BaseCmd
{
	uint32_t Indx;
	/* FilG*, FilS* */
	BaseFill* Repl;
};

struct RUSC: public BaseFilt
{
	double Fact;
	double Thrs;
};

struct RVgC: public BaseFilt
{
	double Expo;
	double Hard;
	double Scal;
	double Shap;
};

struct RcRA: public BaseLayer
{
};

struct Rec
{
	int16_t Scal;
	string  FnPf;
	bool    Enbl;
};

struct RecP: public BaseAdjustment
{
	float RecH;
	float RecS;
	float RecL;
};

struct RegC: public BaseColor
{
};

struct Rstr: public BaseLayer
{
};

struct SBMC: public BaseCmd
{
	EnumT         Blen;
	bool          Pass;
	vector<EnumT> OldB;
	vector<bool>  OldP;
};

struct SCER: public BaseCmd
{
	Sprd*        Root;
	Sprd*        OldR;
	struct Sele* OldS;
	bool         ClSl;
	void*        Femc;
};

struct SCRA: public BaseLayer
{
};

struct SCoP: public BaseAdjustment
{
	bool Rela;
};

struct SDeC: public BaseCmd
{
	string         Desc;
	vector<string> ODes;
	bool           Chan;
};

struct SF2C: public BaseCmd
{
	string         FNam;
	vector<string> Undo;
	vector<string> Redo;
};

struct SGCb
{
	double Azim;
	double Elev;
	double Roll;
};

struct SGrP: public BaseProp
{
	SnpG* SGrd;
	bool  Pixl;
};

struct SHRA: public BaseLayer
{
};

struct SHiP: public BaseAdjustment
{
	float ShdA;
	float HigA;
};

struct SItm
{
	/* v_3DLA*, BCRA*, BWRA*, CBRA*, CMRA*, CPTx*, CrRA*, ExRA*, GrRA*, Grup*, HsRA*, ImgN*, InRA*, LeRA*, MRst*, OCRN*, PCrv*, PfRA*,
	 * PoRA*, RcRA*, Rstr*, SCRA*, SHRA*, SPRA*, Scop*, ShpN*, SlcP*, Slic*, SpTA*, Sprd*, ThRA*, TxtA*, VbRA*, WBRA* */
	BaseLayer* Objt;
	/* CvHS*, TexS* */
	vector<BaseSubSel*> SubS;
};

struct SLAD: public BaseDels
{
	LisA* LstA;
	void* SubA;
	bool  UpIn;
};

struct SLsC: public BaseCmd
{
	int32_t              Mask;
	LSty*                Line;
	vector<struct LDsc*> LSty;
	vector<FDsc*>        OPen;
	vector<void*>        OGly;
};

struct SNAR
{
	int32_t AlnX;
	int32_t AlnY;
	int32_t BndX;
	int32_t BndY;
	double  Offs[2];
	bool    FPre;
	int32_t SclT;
	int32_t Base;
	double  Scal;
	bool    IPre;
};

struct SNEN: public BaseLayer
{
};

struct SNRR: public BaseLayer
{
};

struct SPPp: public BaseProp
{
	SPst* Shpe;
};

struct SPRA: public BaseLayer
{
};

struct SPst
{
	/* ShCE*, ShCR*, ShCg*, ShCl*, ShCr*, ShDA*, ShDS*, ShHt*, ShNR*, ShPi*, ShPy*, ShSS*, ShSg*, ShSt*, ShTr*, ShTz*, ShpD*, ShpT* */
	BaseShape* Shpe;
};

struct SRBr: public BaseBrush
{
};

struct SRst
{
	int32_t        TrCn;
	EnumT          TrAn;
	double         TrFP[2];
	bool           TrFV;
	EnumT          Blnd;
	bool           PasT;
	BlnR*          BlRa;
	double         Xfrm[6];
	double         SrBx[4];
	double         SrPB[4];
	double         FTxS[6];
	string         Desc;
	string         DefD;
	void*          TagC;
	bool           Visi;
	float          Opac;
	float          FOpc;
	vector<void*>  FiEf;
	bool           Edtb;
	bool           CEdb;
	bool           MEtb;
	void*          Data;
	vector<string> Frst;
	vector<string> Scnd;
	EnumT          Hyty;
	string         Hypr;
	EnumT          HyTr;
	EnumT          TWSt;
	double         TWBo[4];
	EnumT          CLiT;
	DyBm*          Bitm;
	int32_t        BitR[4];
	int32_t        BitI[4];
	int32_t        CMsk;
	EnumT          ProT;
	void*          Unpr;
	Matx*          WRot;
	double         Lati;
	double         Long;
	double         Roll;
	double         FOV;
	Quad*          Pspv;
	Per_42*        Psp_42;
	bool           ExtE;
	int32_t        TraC;
};

struct SSAR
{
	int32_t Indx;
	EnumT   Item;
};

struct SSAS
{
	vector<SSAR*> Runs;
};

struct SSFH: public BaseCmd
{
	void*         OldS;
	vector<FDsc*> OldF;
	vector<FDsc*> NewF;
	vector<GlAS*> NewG;
};

struct SSLF: public BaseCmd
{
	void*         OldS;
	vector<FDsc*> OldF;
	vector<FDsc*> NewF;
	vector<void*> NewG;
};

struct SSNS: public BaseCmd
{
	bool         TesC;
	bool         ETxt;
	struct Sele* OldS;
};

struct SSaC: public BaseCmd
{
	int32_t       Alig;
	vector<void*> OldS;
};

struct STPa: public BaseAdjustment
{
	float HlHu;
	float HlSa;
	float ShHu;
	float ShSa;
	float Bala;
};

struct SViC: public BaseCmd
{
	EnumT        Mode;
	bool         Visi;
	vector<bool> OVis;
};

struct ScAN: public BaseScObjs
{
};

struct ScIN: public BaseScObjs
{
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN*, TxtA*, WBRA* */
	BaseLayer* ipnd;
};

struct ScPr: public BaseLayer
{
	vector<int32_t> unbr;
	EnumT           Dire;
	bool            Prev;
	bool            ArtC;
	bool            AAtC;
	bool            CArC;
	bool            Stac;
	/* ScAN*, ScIN*, ScRN* */
	vector<BaseScObjs*> Objs;
	bool                Prog;
	bool                GnHT;
	int32_t             DIdx;
};

struct ScRN: public BaseScObjs
{
	EnumT shdt;
	/* Grup*, Scop*, ShpN*, Sprd* */
	BaseLayer* olpr;
	/* Grup*, PCrv*, Rstr*, Scop*, ShpN* */
	BaseLayer* olns;
	EnumT      olct;
	DeSy*      dtcm;
};

struct Scal
{
	struct ExSc* ExSc;
	string       Path;
	double       ODPI;
};

struct Scop: public BaseLayer
{
	bool VExp;
	/* HSLA*, RGBA* */
	BaseColor* SGNc;
};

struct Sctn
{
	string Head;
	string Body;
	string Pst;
	string LPst;
	string Foot;
	bool   RevO;
};

struct Sele
{
	vector<SItm*> Itms;
	/* Scop*, ShpN*, Sprd* */
	BaseLayer* Layr;
	bool       InRi;
};

struct SetE: public BaseCmd
{
	bool          Edit;
	struct Sele*  OldS;
	vector<EnumT> OlDS;
};

struct ShCE: public BaseShape
{
	float TlAn;
};

struct ShCR: public BaseShape
{
	float TlWd;
	float TlRP;
};

struct ShCg: public BaseShape
{
	float    Hole;
	float    TtSz;
	float    NtSz;
	uint16_t Teth;
};

struct ShCl: public BaseShape
{
	uint16_t Bubl;
};

struct ShCr: public BaseShape
{
	float ArcL;
	float ArcR;
};

struct ShDA: public BaseShape
{
	float Thck;
	EnumT LSty;
	EnumT RSty;
	bool  LLnk;
	float LPr1;
	float LPr2;
	bool  RLnk;
	float RPr1;
	float RPr2;
};

struct ShDS: public BaseShape
{
	float PRad;
};

struct ShHt: public BaseShape
{
	float Sprd;
};

struct ShNR: public BaseShape
{
	bool          AbS_123;
	vector<EnumT> CTyp;
};

struct ShPi: public BaseShape
{
	float AngS;
	float AngE;
};

struct ShPy: public BaseShape
{
	bool Smth;
};

struct ShRN: public BaseLayer
{
};

struct ShRR: public BaseShape
{
};

struct ShSS: public BaseShape
{
	float COut;
};

struct ShSg: public BaseShape
{
	float Angl;
	float Pos0;
	float Pos1;
};

struct ShSt: public BaseShape
{
	float    CrcI;
	float    CrcO;
	float    CrvL;
	float    CrvR;
	uint16_t Pntt;
	bool     Lgcy;
};

struct ShTr: public BaseShape
{
	bool  Fixd;
	float Ball;
	float Bend;
	float Tail;
};

struct ShTz: public BaseShape
{
	float PosL;
	float PosR;
	float PosS;
};

struct Shad: public BaseEffect
{
	bool Knck;
};

struct ShpD: public BaseShape
{
};

struct ShpE: public BaseShape
{
};

struct ShpN: public BaseLayer
{
	ShpN*   ShpM;
	int32_t CExR[4];
	double  Orgn[2];
};

struct ShpT: public BaseShape
{
};

struct SlcP: public BaseLayer
{
	bool          EmMd;
	bool          InBl;
	int32_t       SRct[4];
	vector<Slic*> Slcs;
	bool          Init;
	/* EOPn*, FExO* */
	BaseExport* ExOp;
};

struct Slic: public BaseLayer
{
	int32_t Rect[4];
};

struct Smps
{
	EnumT  smTy;
	double smPt[2];
	bool   smVi;
};

struct SnpG
{
	double   Siz0;
	double   Gut0;
	int32_t  Dvs0;
	double   Siz1;
	double   Gut1;
	int32_t  Dvs1;
	double   Siz2;
	double   Gut2;
	int32_t  Dvs2;
	EnumT    Mode;
	bool     Unfm;
	bool     AUpA;
	bool     FxAs;
	double   AspR;
	double   UAsR;
	double   Ang0;
	double   Ang1;
	double   AngU;
	EnumT    Horz;
	EnumT    Vert;
	EnumT    Intm;
	EnumT    UpRl;
	uint32_t IDvs;
	SGCb*    Cube;
	void*    CRot;
	double   CScl;
};

struct SoPP: public BaseAdjustment
{
	ICCP* Prof;
	EnumT Intn;
	bool  BPCs;
	bool  SPGC;
};

struct SpRV
{
	vector<SpRe*> Rcts;
};

struct SpRe
{
	double       Rect[4];
	struct Sprd* Sprd;
};

struct SpTA: public BaseLayer
{
};

struct Spln
{
	int32_t        Cnt;
	vector<double> Vals;
	bool           Linr;
	double         Bnd1;
	double         BndN;
};

struct Sprd: public BaseLayer
{
	int32_t       PagC;
	bool          PagF;
	bool          PagD;
	double        SprB[4];
	bool          SprT;
	SRst*         RasS;
	SRst*         Ras2;
	double        bled[4];
	SlcP*         SlcP;
	RGBA*         BgrC;
	vector<Smps*> smps;
	vector<VwPD*> VPts;
	bool          Fcng;
	bool          R1st;
	PBxR*         bbxs;
	double        Mrgn[4];
	double        UOrg[2];
};

struct StBl
{
	GStr* Glyp;
	GlAS* GAtt;
	PaAS* PAtt;
};

struct StkN: public BaseLayer
{
	EnumT SOpe;
};

struct Stop
{
	double Posn;
	EnumT  Type;
	EnumT  Lead;
	GStr*  LStr;
	ChGl*  DGly;
	bool   FRgh;
	TxtA*  IStr;
	TexS*  GSel;
	TexS*  PSel;
};

struct Strk: public BaseEffect
{
	EnumT Alig;
	EnumT Ftyp;
};

struct Stry
{
	vector<StBl*> Blok;
	bool          iTab;
};

struct TBFR
{
	vector<TbFt*> fmts;
};

struct TBSO
{
	bool InHd;
	bool CsSn;
	bool NAWd;
};

struct TCel
{
	EnumT  AliY;
	double Inse[4];
};

struct TCls
{
	int32_t       Size[2];
	vector<TCel*> Cell;
};

struct TEdg
{
	LDsc* Line;
	FDsc* Fill;
};

struct TEds
{
	int32_t       Size[2];
	vector<TEdg*> Edge;
};

struct TExM: public BaseProp
{
	string TExl;
};

struct TMpP
{
	double Strg;
	double LocC;
	double ShaI;
	double HigI;
	bool   SHiE;
	double Expo;
	bool   ExpE;
	double Cont;
	bool   ConE;
	double Satu;
	double Vibr;
	double Blap;
	double Whip;
	double WhiB;
	double Tint;
	bool   WhBE;
	double DRRd;
	double DRAm;
	bool   DREn;
	CrvP*  Curv;
	bool   CrEn;
};

struct TPos
{
	vector<double> Posn;
	vector<double> MSiz;
};

struct TStS
{
	vector<TSty*> Styl;
};

struct TSty
{
	string Name;
	EnumT  Type;
	bool   Show;
	CoDe*  Delt;
	string Base;
	string Foll;
	string Next;
};

struct TabS: public BaseAtt
{
	vector<Stop*> Stop;
	ChGl*         DecG;
};

struct Tabl
{
	TPos*  CPos;
	TPos*  RPos;
	TEds*  CEdg;
	TEds*  REdg;
	TCls*  Cell;
	TbFt*  TFmt;
	double Inst[4];
};

struct TbBF
{
	FDsc* Fill;
	LDsc* LSty;
};

struct TbCF
{
	string        Name;
	vector<TbBF*> Brds;
	FDsc*         Fill;
	string        PSty;
	double        Inst[4];
	EnumT         AlnY;
};

struct TbFr: public BaseFrms
{
	Tabl* Tabl;
};

struct TbFt
{
	vector<TbCF*> Clls;
	vector<TbCF*> Fmts;
	int32_t       Size[2];
	int32_t       Brds[4];
	string        Name;
	double        ppi;
	bool          IsDf;
	FDsc*         Fill;
	FDsc*         LFll;
	LDsc*         LSty;
	double        Inst[4];
};

struct TexS: public BaseSubSel
{
	int32_t SAnc;
	int32_t SCar;
	bool    SACF;
	bool    SCCF;
	bool    SmSp;
};

struct ThRA: public BaseLayer
{
};

struct ThrP: public BaseAdjustment
{
	float Thre;
	float Fals;
	float True;
};

struct TocA: public BaseAtt
{
};

struct TonP: public BaseProp
{
	TMpP* Para;
};

struct TrCm: public BaseCmd
{
	bool                     TrRS;
	bool                     FTxS;
	double                   Xfrm[6];
	double                   ORST[6];
	double                   NotT[6];
	SpRV*                    OIRe;
	SpRV*                    NIRe;
	vector<uint32_t>         OTCn;
	vector<EnumT>            OTAn;
	bool                     PPFP;
	vector<array<double, 6>> OldA;
	vector<array<double, 6>> OFTS;
	bool                     Merg;
	bool                     CRas;
	bool                     CorC;
	vector<array<double, 6>> OlCT;
	vector<array<double, 6>> OPCT;
	bool                     RArt;
	bool                     AjPF;
	bool                     DupN;
	Dupl*                    DupC;
	void*                    PFPC;
	MvNC*                    MovC;
	Sprd*                    RpSd;
	void*                    SCSC;
	void*                    SCsC;
};

struct TrSl: public BaseCmd
{
	vector<Slic*> Slcs;
	vector<void*> Nods;
	int32_t       Ofst[2];
	EnumT         Mthd;
};

struct TxFU
{
};

struct TxFl
{
	/* CPTx*, TxtA*, TxtF*, TxtT* */
	vector<BaseLayer*> Nods;
	bool               HOvr;
	ILTf*              TFLK;
};

struct TxtA: public BaseLayer
{
	double bbox[4];
};

struct TxtF: public BaseLayer
{
	vector<PCrv*> WSCh;
	bool          bflp;
};

struct TxtS: public BaseLayer
{
};

struct TxtT: public BaseLayer
{
};

struct UANC: public BaseCmd
{
	struct Sele* OldS;
};

struct UVCn
{
	double  UPPI;
	int32_t SPxM;
	double  VDPI;
};

struct UnSR
{
	int32_t BegI;
	int32_t EndI;
};

struct UndR
{
	uint32_t      Fetr;
	int32_t       Valu;
	ShpN*         Node;
	double        Xfrm[6];
	double        FTxS[6];
	Grup*         Grou;
	Scop*         Pare;
	void*         NexS;
	vector<UndR*> Chil;
};

struct Undo
{
	v_CB4* On;
	v_CB5* Off;
};

struct VbRA: public BaseLayer
{
};

struct VibP: public BaseAdjustment
{
	int32_t Vibr;
	float   Satu;
};

struct VwPD
{
	double   vpFr;
	double   vpCt[2];
	string   vpPn;
	uint32_t vpSI;
	bool     vpIM;
};

struct WBRA: public BaseLayer
{
};

struct WhBP: public BaseAdjustment
{
	int32_t  WhBa;
	float    WBTi;
	uint16_t WhBV;
};

struct XCfg
{
	vector<ExCm*> Fmts;
	string        Path;
};

struct XMgC: public BaseCmd
{
	vector<XCfg*> Undo;
	vector<void*> Redo;
	FlagsT        Chgs;
};

struct XStC: public BaseCmd
{
	vector<XCfg*> Undo;
	vector<void*> Redo;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB1
{
	uint8_t       byte;
	uint32_t      size;
	vector<v_C1*> list;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB2
{
	uint8_t       byte;
	vector<v_C2*> list;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB3
{
	uint8_t           byte;
	bool              bool_v;
	vector<curve18_t> crvs;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB4
{
	uint8_t  byte;
	uint32_t int_v;
	double   vecd[2];
	int32_t  veci[2];
	EnumT    enum_v;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_CB5
{
	uint8_t  byte;
	uint32_t int_v;
	double   vcd1[2];
	int32_t  vci1[2];
	double   vcd2[2];
	int32_t  vci2[2];
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_C1
{
	bool              bool_v;
	vector<curve18_t> crvs;
};

/* NOLINTNEXTLINE(readability-identifier-naming) */
struct v_C2
{
	vector<int32_t> ints;
	vector<double>  dbls;
	vector<uint8_t> byts;
};

#pragma pack(pop)

} // namespace AffinityReader::CppModel
#endif /* AFFINITY_CPPSTRUCTS_H */
